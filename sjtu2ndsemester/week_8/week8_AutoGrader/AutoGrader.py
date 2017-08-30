# -*- coding: utf-8 -*-

import re
import os
import os.path
import subprocess
import platform

hw_title = 'week8'
trace_cnt = 10
trace_max_score = 10

is_windows = platform.system() == 'Windows'

exe_ext = '.exe' if is_windows else ''

stu_dict = {}

def pause_and_exit():
    if is_windows:
        print
        print 'Press Enter to exit...',
        raw_input()
    raise SystemExit

def check_dependency():
    with open('./temp/test_g++.txt', 'w') as fout_test:
            subprocess.call('g++', shell=True, stdout=fout_test, stderr=fout_test)
    fin_test_gpp = open('./temp/test_g++.txt', 'r')
    test_gpp_content = fin_test_gpp.read()
    if 'g++: fatal error: no input files' not in test_gpp_content:
        print 'Error: g++ is not correctly installed'
        pause_and_exit()

    if is_windows:
        print 'Warning: Valgrind is not available for Windows'
        print 'Memory tests will not be performed'
        print '---------------------------------------------'
    else:
        with open('./temp/test_valgrind.txt', 'w') as fout_test:
            subprocess.call('valgrind', shell=True, stdout=fout_test, stderr=fout_test)
        fin_test_valgrind = open('./temp/test_valgrind.txt', 'r')
        test_valgrind_content = fin_test_valgrind.read()
        if 'valgrind: no program specified' not in test_valgrind_content:
            print 'Error: Valgrind is not correctly installed'
            pause_and_exit()

def load_stu_dict():
    try:
        fin_stu = open('stu_list.txt', 'r')
        for line in fin_stu:
            s = line.replace('\n', '').strip()
            if s:
                data = s.split('\t')
                stu_dict[data[0]] = data[1]
    except:
        pass

def get_name_by_stuid(stuid):
    if stuid in stu_dict:
        return stu_dict[stuid]
    else:
        return 'N/A'

def get_stuid_by_filename(filename):
    result = re.findall(hw_title + r'_(\d+)\.h', filename)
    if result:
        return result[0]
    else:
        return '[%s]' % (filename)

def generate_grade_list():
    grade_list = []
    for parent, dirnames, filenames in os.walk('./submits'):
        for filename in filenames:
            grade_list.append({'file': filename, 'stuid': get_stuid_by_filename(filename)})
    return grade_list

def fix_sth(s):
    return s.replace('#include "stdafx.h"', '').replace('#include "Stdafx.h"', '').replace('#pragma once', '')

def compile_and_link(grade_item, trace_no):
    fin_header = open('./header/header.h', 'r')
    header_content = fin_header.read()
    fin_header.close()

    fin_stu = open('./submits/' + grade_item['file'], 'r')
    stu_content = fix_sth(fin_stu.read())
    fin_stu.close()

    fin_trace = open('./traces/trace%d.cpp' % (trace_no), 'r')
    trace_content = fin_trace.read()
    fin_trace.close()

    merged_filename = './temp/%s_%s_merged_trace%d' % (hw_title, grade_item['stuid'], trace_no)
    fout_tmp = open(merged_filename + '.cpp', 'w')
    fout_tmp.write(header_content + '\n' + stu_content + '\n' + trace_content + '\n')
    fout_tmp.close()

    with open(os.devnull, 'wb') as devnull:
        subprocess.call(['g++', '-g', '-std=c++11', merged_filename + '.cpp', '-o', merged_filename + exe_ext], stdout=devnull, stderr=devnull)

    if os.path.isfile(merged_filename + exe_ext):
        return True
    else:
        with open('./report/CE_detail/%s_%s_trace%d_CE.txt' % (hw_title, grade_item['stuid'], trace_no), 'w') as fout_report:
            subprocess.call(['g++', '-g', '-std=c++11', merged_filename + '.cpp', '-o', merged_filename + exe_ext], stdout=fout_report, stderr=fout_report)
        return False

def run_program(grade_item, trace_no):
    merged_filename = './temp/%s_%s_merged_trace%d' % (hw_title, grade_item['stuid'], trace_no)

    with open(merged_filename + '.out', 'w') as fout_stu:
        try:
            subprocess.call([merged_filename + exe_ext, ''], stdout=fout_stu)
            return True
        except KeyboardInterrupt:
            return False

def line_diff(linelist1, linelist2):
    if linelist1 == linelist2:
        return 0
    else:
        lineset1 = set(linelist1)
        lineset2 = set(linelist2)
        diff1 = len(lineset1 - lineset2)
        diff2 = len(lineset2 - lineset1)
        factor1 = float(max(diff1, diff2)) / max(len(lineset1), len(lineset2))
        factor2 = float(abs(len(linelist1) - len(linelist2))) / max(len(linelist1), len(linelist2))
        if factor2 == 0.0:
            factor2 = 0.1
        return max(factor1, factor2)

def compare_ans(grade_item, trace_no):
    linelist_stu = []
    linelist_std = []

    fin_stu = open('./temp/%s_%s_merged_trace%d.out' % (hw_title, grade_item['stuid'], trace_no), 'r')
    for line in fin_stu:
        s = line.replace('\n', '').strip()
        if s:
            linelist_stu.append(s)

    fin_std = open('./traces/trace%d.out' % (trace_no), 'r')
    for line in fin_std:
        s = line.replace('\n', '').strip()
        if s:
            linelist_std.append(s)

    diff_factor = line_diff(linelist_stu, linelist_std)
    if diff_factor == 0:
        return trace_max_score
    else:
        fout_WA_report = open('./report/WA_detail/%s_%s_trace%d_WA.txt' % (hw_title, grade_item['stuid'], trace_no), 'w')
        fout_WA_report.write('Student output:\n')
        for line in linelist_stu:
            fout_WA_report.write(line + '\n')
        fout_WA_report.write('---------------------------------------------\n')
        fout_WA_report.write('Standard output:\n')
        for line in linelist_std:
            fout_WA_report.write(line + '\n')

        return trace_max_score * (1 - diff_factor)

def mem_test(grade_item, trace_no):
    merged_filename = './temp/%s_%s_merged_trace%d' % (hw_title, grade_item['stuid'], trace_no)

    with open(os.devnull, 'wb') as devnull:
        subprocess.call(['valgrind', '--log-file=%s.log' % (merged_filename), merged_filename], stdout=devnull, stderr=devnull)

    fin_log = open(merged_filename + '.log', 'r')
    log_content = fin_log.read()

    has_leak = False

    result = re.findall(r'definitely lost: (\d+) bytes in (\d+) blocks', log_content)
    if result:
        if result[0][0] != '0' or result[0][1] != '0':
            has_leak = True
    result = re.findall(r'indirectly lost: (\d+) bytes in (\d+) blocks', log_content)
    if result:
        if result[0][0] != '0' or result[0][1] != '0':
            has_leak = True
    result = re.findall(r'possibly lost: (\d+) bytes in (\d+) blocks', log_content)
    if result:
        if result[0][0] != '0' or result[0][1] != '0':
            has_leak = True

    has_double_free = 'Invalid free() / delete / delete[] / realloc()' in log_content

    has_invalid_mem_access = 'Invalid read' in log_content or 'Invalid write' in log_content

    if has_leak or has_double_free or has_invalid_mem_access:
        with open(os.devnull, 'wb') as devnull:
            subprocess.call(['valgrind', '--leak-check=full', '--log-file=./report/BadMem_detail/%s_%s_trace%d_BadMem.txt' % (hw_title, grade_item['stuid'], trace_no), merged_filename], stdout=devnull, stderr=devnull)

    ret_list = []

    if has_leak:
        ret_list.append('Leak')
    if has_double_free:
        ret_list.append('Double Free')
    if has_invalid_mem_access:
        ret_list.append('Invalid Mem Access')

    ret_str = ' & '.join(ret_list)
    if ret_str:
        return ret_str
    else:
        return 'Good'

def grade(grade_item):
    print 'Grading student %s...' % (grade_item['stuid'])
    print

    trace_status = [''] * trace_cnt
    trace_score = [0] * trace_cnt
    trace_mem = ['N/A'] * trace_cnt

    for i in xrange(trace_cnt):
        print 'Test case %d:' % (i)

        if not compile_and_link(grade_item, i):
            trace_status[i] = 'CE'
            print 'Status: CE'
        else:
            if run_program(grade_item, i):
                trace_score[i] = compare_ans(grade_item, i)
                if trace_score[i] == trace_max_score:
                    trace_status[i] = 'AC'
                else:
                    trace_status[i] = 'WA'
                    
                print 'Status:', trace_status[i], 'Score:', trace_score[i],

                if is_windows:
                    trace_mem[i] = 'Unable to test memory on Windows'
                else:
                    trace_mem[i] = mem_test(grade_item, i)
                print 'Memory:', trace_mem[i]

            else:
                trace_status[i] = 'TLE'
                print 'Status: TLE'

        if trace_status[i] != 'AC' or trace_mem[i] not in ['Good', 'Unable to test memory on Windows']:
            if is_windows:
                with open(os.devnull, 'wb') as devnull:
                    subprocess.call('copy .\\temp\\%s_%s_merged_trace%d.cpp .\\report\\error_src\\' % (hw_title, grade_item['stuid'], i), shell=True, stdout=devnull, stderr=devnull)
            else:
                subprocess.call('cp ./temp/%s_%s_merged_trace%d.cpp ./report/error_src/' % (hw_title, grade_item['stuid'], i), shell=True)
        print

    fout_report = open('./report/grades/%s_%s_report.txt' % (hw_title, grade_item['stuid']), 'w')
    fout_report.write('Report for student %s(%s):\n' % (grade_item['stuid'], get_name_by_stuid(grade_item['stuid'])))
    fout_report.write('Output:\n')
    for i in xrange(trace_cnt):
        fout_report.write('Test case %d: %s\t%.2f/%d\n' % (i, trace_status[i], trace_score[i], trace_max_score))
    fout_report.write('---------------------------------------------\n')
    fout_report.write('Memory:\n')
    for i in xrange(trace_cnt):
        fout_report.write('Test case %d: %s\n' % (i, trace_mem[i]))
    fout_report.write('---------------------------------------------\n')
    fout_report.write('Summary:\n')
    fout_report.write('Output score: %.2f/%d\n' % (sum(trace_score), trace_max_score * trace_cnt))
    fout_report.write('Memory score: %d/%d\n' % (trace_mem.count('Good'), trace_cnt))

    print '---------------------------------------------'

def main():
    check_dependency()

    load_stu_dict()

    grade_list = generate_grade_list()
    for grade_item in grade_list:
        grade(grade_item)

    print 'Done.'

    pause_and_exit()

main()
