#include "../../gui/GUI.h"

using namespace Graph_lib;

struct Lines_window : Graph_lib::Window
{
	Lines_window(Point xy, int w, int h, const string &title);

private:
	Open_polyline lines;

	Button next_button;
	Button quit_button;

	In_box next_x;
	In_box next_y;

	Out_box xy_out;

	// coloring options
	Menu color_menu;
	Button menu_button;

	// styling options
	Menu style_menu;
	Button style_button;
	// track menu state
	bool style_open;

	void next();
	void quit();

	bool wait_for_button();

	void change(Color c) { lines.set_color(c); }
	void change_style(Line_style s) { lines.set_style(s); }

	void hide_color_menu()
	{
		color_menu.hide();
		menu_button.show();
		style_button.move(0, -50);
		style_menu.move(0, -50);
		// on move the widget resets to visible
		if (!style_open)
			style_menu.hide();
		else
			style_button.hide();
	}

	void hide_style_menu()
	{
		style_menu.hide();
		style_button.show();
		style_open = false;
	}

	static void cb_red(Address, Address);
	static void cb_blue(Address, Address);
	static void cb_black(Address, Address);
	static void cb_menu(Address, Address);

	static void cb_solid(Address, Address);
	static void cb_dash(Address, Address);
	static void cb_dot(Address, Address);
	static void cb_dashdot(Address, Address);
	static void cb_dashdotdot(Address, Address);
	static void cb_style_menu(Address, Address);

	void red_pressed()
	{
		change(Color::red);
		hide_color_menu();
	}

	void blue_pressed()
	{
		change(Color::blue);
		hide_color_menu();
	}

	void black_pressed()
	{
		change(Color::black);
		hide_color_menu();
	}

	void color_pressed()
	{
		menu_button.hide();
		color_menu.show();

		style_button.move(0, 50);
		style_menu.move(0, 50);
		if (!style_open)
			style_menu.hide();
		else
			style_button.hide();
	}

	void solid_pressed()
	{
		change_style(Line_style::solid);
		hide_style_menu();
	}

	void dash_pressed()
	{
		change_style(Line_style::dash);
		hide_style_menu();
	}

	void dot_pressed()
	{
		change_style(Line_style::dot);
		hide_style_menu();
	}

	void dashdot_pressed()
	{
		change_style(Line_style::dashdot);
		hide_style_menu();
	}

	void dashdotdot_pressed()
	{
		change_style(Line_style::dashdotdot);
		hide_style_menu();
	}

	void style_pressed()
	{
		style_button.hide();
		style_menu.show();
		style_open = true;
	}
};