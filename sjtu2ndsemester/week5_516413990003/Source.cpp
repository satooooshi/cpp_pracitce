
#include"Graph.h"
#include"Simple_window.h"
#include"std_lib_facilities.h"

int main() {

	int width = 800;
	int height = 500;
	using namespace Graph_lib;
	Point t1{100,100};
	Simple_window win{ t1,width,height,"Canvas_olympic" };

	//blue circle
	Circle c1{ Point {width/9*3,height/6*2},80 };
	Circle c2{ Point {width/9*3,height/6*2},81};
	Circle c3{ Point{ width/9*3,height/6*2},82 };
	Circle c4{ Point{ width/9*3,height/6*2},83 };
	Circle c5{ Point{ width / 9 * 3,height / 6 * 2 },84 };
	c1.set_color(Color::blue);
	c2.set_color(Color::blue);
	c3.set_color(Color::blue);
	c4.set_color(Color::blue);
	c5.set_color(Color::blue);
	win.attach(c1);
	win.attach(c2);
	win.attach(c3);
	win.attach(c4);
	win.attach(c5);

	//black circle
	Circle c6{ Point{ width / 9 * 5,height / 6 * 2 },80 };
	Circle c7{ Point{ width / 9 * 5,height / 6 * 2 },81 };
	Circle c8{ Point{ width / 9 * 5,height / 6 * 2 },82 };
	Circle c9{ Point{ width / 9 * 5,height / 6 * 2 },83 };
	Circle c10{ Point{ width / 9 * 5,height / 6 * 2 },84 };
	c6.set_color(Color::black);
	c7.set_color(Color::black);
	c8.set_color(Color::black);
	c9.set_color(Color::black);
	c10.set_color(Color::black);
	win.attach(c6);
	win.attach(c7);
	win.attach(c8);
	win.attach(c9);
	win.attach(c10);

	//red circle
	Circle c11{ Point{ width / 9 * 7,height / 6 * 2 },80 };
	Circle c12{ Point{ width / 9 * 7,height / 6 * 2 },81 };
	Circle c13{ Point{ width / 9 * 7,height / 6 * 2 },82 };
	Circle c14{ Point{ width / 9 * 7,height / 6 * 2 },83 };
	Circle c15{ Point{ width / 9 * 7,height / 6 * 2 },84 };
	c11.set_color(Color::red);
	c12.set_color(Color::red);
	c13.set_color(Color::red);
	c14.set_color(Color::red);
	c15.set_color(Color::red);
	win.attach(c11);
	win.attach(c12);
	win.attach(c13);
	win.attach(c14);
	win.attach(c15);

	//yellow circle
	Circle c16{ Point{ width / 9 * 4,height / 6 * 3 },80 };
	Circle c17{ Point{ width / 9 * 4,height / 6 * 3 },81 };
	Circle c18{ Point{ width / 9 * 4,height / 6 * 3 },82 };
	Circle c19{ Point{ width / 9 * 4,height / 6 * 3 },83 };
	Circle c20{ Point{ width / 9 * 4,height / 6 * 3 },84 };
	c16.set_color(Color::yellow);
	c17.set_color(Color::yellow);
	c18.set_color(Color::yellow);
	c19.set_color(Color::yellow);
	c20.set_color(Color::yellow);
	win.attach(c16);
	win.attach(c17);
	win.attach(c18);
	win.attach(c19);
	win.attach(c20);

	//green circle
	Circle c21{ Point{ width / 9 * 6,height / 6 * 3 },80 };
	Circle c22{ Point{ width / 9 * 6,height / 6 * 3 },81 };
	Circle c23{ Point{ width / 9 * 6,height / 6 * 3 },82 };
	Circle c24{ Point{ width / 9 * 6,height / 6 * 3 },83 };
	Circle c25{ Point{ width / 9 * 6,height / 6 * 3 },84 };
	c21.set_color(Color::green);
	c22.set_color(Color::green);
	c23.set_color(Color::green);
	c24.set_color(Color::green);
	c25.set_color(Color::green);
	win.attach(c21);
	win.attach(c22);
	win.attach(c23);
	win.attach(c24);
	win.attach(c25);

	
	
	win.wait_for_button();
	return 0;

}



