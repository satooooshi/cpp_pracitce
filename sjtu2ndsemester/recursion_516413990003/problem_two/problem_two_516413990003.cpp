//student No.516413990003 

#include"Graph.h"
#include"Simple_window.h"
#include"std_lib_facilities.h"
#include"GUI.h"
#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::stringstream
#include <queue>

#include<vector>
#include<cmath>
using namespace std;

Vector_ref<Graph_lib::Rectangle>vec;

void fractal(double x,double y,double l,int order,int cnt=1) {
	if(cnt==1)vec.push_back(new Graph_lib::Rectangle(Point{ x,y }, l, l));
	if (order == 0) {  return; }
	else {
		for (int i = 0; i < 4 * cnt; ++i) {
			vec.push_back(new Graph_lib::Rectangle(Point{ l / 4 * i+x,l / 4 * i+y }, l / 4, l / 4));
		}
		fractal(x,y,l/4,order-1,cnt*4);
	}
}

int main() {

	double x, y, L, order;
	cout << "Enter x y L order : ";
	cin >> x >> y >> L >> order;

	Simple_window win{ Point{ 100,100 },1000,1000,"fractal" };

//**********************************
//Enter fractal(x,y,L,order)
	fractal(x,y,L,order);
//**********************************
	for (int i = 0; i < vec.size(); ++i) {
		vec[i].set_color(Color::red);
		win.attach(vec[i]);
	}
	win.wait_for_button();


	return 0;
}