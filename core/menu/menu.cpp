#include "menu.hpp"


auto do_frame = [&](std::int32_t x, std::int32_t y, std::int32_t w, std::int32_t h, color bg) {
	render::draw_filled_rect(x, y, w, h, bg);
	render::draw_line(x, y + 9, x, y + h,color::black());
	render::draw_line(x, y + h, x + w - 1, y + h, color::black());
	render::draw_line(x + w - 1, y + h, x + w - 1, y + 9, color::black());
	/*render::draw_filled_rect(x, y, w, 30, header_text);
	render::draw_filled_rect(x, y + 30, w, 2, header_line);
	*/
};

void menu::render() {
	if (!variables::menu::opened)
		return;
	do_frame(variables::menu::x, variables::menu::y, variables::menu::w, variables::menu::h, color(30, 30, 30, 255));

	menu_framework::tab(variables::menu::x, variables::menu::y, render::fonts::watermark_font, "visuals", menu::current_tab, 0);
	menu_framework::tab(variables::menu::x + 100, variables::menu::y, render::fonts::watermark_font, "aimbot", menu::current_tab, 1);
	menu_framework::tab(variables::menu::x + 200, variables::menu::y, render::fonts::watermark_font, "misc", menu::current_tab, 2);
	menu_framework::tab(variables::menu::x + 300, variables::menu::y, render::fonts::watermark_font, "config", menu::current_tab, 3);
	switch (current_tab) {
	case 0:
		menu_framework::check_box(variables::menu::x + 10, variables::menu::y + 20, render::fonts::button_font, "visuals", variables::bVisuals);
		if (variables::bVisuals) {
			menu_framework::check_box(variables::menu::x + 10, variables::menu::y + 35, render::fonts::button_font, "tracers", variables::visuals::tracers);
			if (variables::visuals::tracers) {
				menu_framework::selection_interface(variables::menu::x + 50, variables::menu::y + 35, variables::tracer_origin_selections, variables::tracer_origin, variables::tracer_origin_selections_opened);
			}
			menu_framework::check_box(variables::menu::x + 10, variables::menu::y + 65, render::fonts::button_font, "box", variables::visuals::box);
			if (variables::visuals::box) {
				menu_framework::selection_interface_2(variables::menu::x + 50, variables::menu::y + 65, variables::visuals::box_esp::box_selections, variables::visuals::box_esp::box_selected, variables::visuals::box_esp::box_selections_opened);
			}
			menu_framework::check_box(variables::menu::x + 10, variables::menu::y + 80, render::fonts::button_font, "glow", variables::visuals::glow);
			menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 20, render::fonts::button_font, "chams", variables::visuals::chams);
			if (variables::visuals::chams) {
				menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 30, render::fonts::button_font, "weapons", variables::visuals::cham::weapon);
				if (variables::visuals::cham::weapon) {
					menu_framework::selection_interface(variables::menu::x + 280, variables::menu::y + 30, variables::materials_selections, variables::weapons, variables::weapons_opened);
					menu_framework::color_selection(variables::menu::x + 340, variables::menu::y + 30, variables::weapon_color, variables::weapon_color_bool);
				}
				menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 40, render::fonts::button_font, "hands", variables::visuals::cham::arms);
				if (variables::visuals::cham::arms && !variables::weapons_opened) {
					menu_framework::selection_interface(variables::menu::x + 280, variables::menu::y + 40, variables::materials_selections, variables::arms, variables::arms_opened);
					if (!variables::weapon_color_bool) {
						menu_framework::color_selection(variables::menu::x + 340, variables::menu::y + 40, variables::arms_color, variables::arms_color_bool);
					}
				}
				menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 50, render::fonts::button_font, "sleeves", variables::visuals::cham::sleeves);
				if (variables::visuals::cham::sleeves && !variables::weapons_opened && !variables::arms_opened) {
					menu_framework::selection_interface(variables::menu::x + 280, variables::menu::y + 50, variables::materials_selections, variables::sleeves, variables::sleeves_opened);
					if (!variables::weapon_color_bool) {
						menu_framework::color_selection(variables::menu::x + 340, variables::menu::y + 50, variables::sleeves_color, variables::sleeves_color_bool);
					}
				}
				menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 60, render::fonts::button_font, "vis friend", variables::visuals::cham::friendly);
				menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 70, render::fonts::button_font, "ivis friend", variables::visuals::cham::friendly_invis);
				if (variables::visuals::cham::friendly && !variables::weapons_opened && !variables::arms_opened && !variables::sleeves_opened) {
					menu_framework::selection_interface(variables::menu::x + 280, variables::menu::y + 60, variables::materials_selections, variables::friendly, variables::friendly_opened);
					if (!variables::weapon_color_bool && !variables::arms_color_bool) {
						menu_framework::color_selection(variables::menu::x + 340, variables::menu::y + 60, variables::friendly_color, variables::friendly_color_bool);
					}
				}
				if (variables::visuals::cham::friendly_invis && !variables::weapons_opened && !variables::arms_opened && !variables::friendly_opened && !variables::sleeves_opened) {
					menu_framework::selection_interface(variables::menu::x + 280, variables::menu::y + 70, variables::materials_selections, variables::friendly_invis, variables::friendly_opened_invis);
					if (!variables::weapon_color_bool && !variables::arms_color_bool) {
						menu_framework::color_selection(variables::menu::x + 340, variables::menu::y + 70, variables::friendly_color_invis, variables::friendly_color_bool_invis);
					}
				}
				menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 80, render::fonts::button_font, "vis enemy", variables::visuals::cham::enemy);
				menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 90, render::fonts::button_font, "ivis enemy", variables::visuals::cham::enemy_invis);
				if (variables::visuals::cham::enemy && !variables::weapons_opened && !variables::friendly_opened && !variables::arms_opened && !variables::friendly_opened_invis && !variables::sleeves_opened) {
					menu_framework::selection_interface(variables::menu::x + 280, variables::menu::y + 80, variables::materials_selections, variables::enemy, variables::enemy_opened);
					if (!variables::weapon_color_bool && !variables::arms_color_bool && !variables::friendly_color_bool) {
						menu_framework::color_selection(variables::menu::x + 340, variables::menu::y + 80, variables::enemy_color, variables::enemy_color_bool);
					}
				}
				if (variables::visuals::cham::enemy_invis && !variables::weapons_opened && !variables::friendly_opened && !variables::arms_opened && !variables::friendly_opened_invis && !variables::enemy_opened && !variables::sleeves_opened) {
					menu_framework::selection_interface(variables::menu::x + 280, variables::menu::y + 90, variables::materials_selections, variables::enemy_invis, variables::enemy_opened_invis);
					if (!variables::weapon_color_bool && !variables::arms_color_bool && !variables::friendly_color_bool && !variables::enemy_opened) {
						menu_framework::color_selection(variables::menu::x + 340, variables::menu::y + 90, variables::enemy_color_invis, variables::enemy_color_bool_invis);
					}
				}
				menu_framework::check_box(variables::menu::x + 230, variables::menu::y + 100, render::fonts::button_font, "draw ground items and ragdolls", variables::visuals::cham::extend_chams);
			}
		}
		break;
	case 1:
		menu_framework::check_box(variables::menu::x + 10, variables::menu::y + 20, render::fonts::button_font, "aimbot", variables::bAimbot);
		if (variables::bAimbot) {
			menu_framework::selection_interface(variables::menu::x + 90, variables::menu::y + 20, variables::aim_type_selections, variables::aim_type, variables::aim_type_selections_opened);
			menu_framework::selection_interface(variables::menu::x + 150, variables::menu::y + 20, variables::aim_priority_selections, variables::aim_priority, variables::aim_priority_selections_opened);
			menu_framework::check_box(variables::menu::x + 10, variables::menu::y + 35, render::fonts::button_font, "rcs", variables::aimbot::rcs);
			menu_framework::check_box(variables::menu::x + 10, variables::menu::y + 50, render::fonts::button_font, "team check", variables::aimbot::teamcheck);
			menu_framework::check_box(variables::menu::x + 10, variables::menu::y + 65, render::fonts::button_font, "visible check", variables::aimbot::vischeck);
			menu_framework::check_box(variables::menu::x + 10, variables::menu::y + 80, render::fonts::button_font, "sticky", variables::aimbot::sticky);
			menu_framework::check_box(variables::menu::x + 10, variables::menu::y + 95, render::fonts::button_font, "transparent check", variables::aimbot::transpcheck);
			menu_framework::check_box(variables::menu::x + 10, variables::menu::y + 110, render::fonts::button_font, "smoothing", variables::aimbot::smooth);
			menu_framework::check_box(variables::menu::x + 10, variables::menu::y + 125, render::fonts::button_font, "fov", variables::aimbot::fovcheck);
			menu_framework::check_box(variables::menu::x + 10, variables::menu::y + 140, render::fonts::button_font, "auto shoot", variables::aimbot::autoshoot);
			if (variables::aimbot::autoshoot) {
				menu_framework::check_box(variables::menu::x + 70, variables::menu::y + 140, render::fonts::button_font, "auto scope", variables::aimbot::autoscope);
			}
			menu_framework::check_box(variables::menu::x + 10, variables::menu::y + 155, render::fonts::button_font, "randomisation", variables::aimbot::random);
			if (variables::aimbot::random) {
				menu_framework::slider(variables::menu::x + 70, variables::menu::y + 155, 125, render::fonts::button_font, "randomis", variables::aimbot::randomisation, 0, 9);
			}
			menu_framework::check_box(variables::menu::x + 10, variables::menu::y + 170, render::fonts::button_font, "show target info", variables::aimbot::TargetInfo);
			menu_framework::check_box(variables::menu::x + 10, variables::menu::y + 185, render::fonts::button_font, "activations", variables::aimbot::b1);
			if (variables::aimbot::b1) {
				menu_framework::selection_interface_2(variables::menu::x + 90, variables::menu::y + 185, variables::aimbot_active_selections, variables::aimbot_active_selected, variables::aimbot_active_opened);
			}
			menu_framework::check_box(variables::menu::x + 10, variables::menu::y + 200, render::fonts::button_font, "deactivations", variables::aimbot::b2);
			if (variables::aimbot::b2 && !variables::aimbot_active_opened) {
				menu_framework::selection_interface_2(variables::menu::x + 90, variables::menu::y + 200, variables::aimbot_trigs_selections, variables::aimbot_trigs_selected, variables::aimbot_trigs_opened);
			}
			if (variables::aimbot::smooth) {
				menu_framework::slider(variables::menu::x + 70, variables::menu::y + 110, 125, render::fonts::button_font, "smoothing", variables::aimbot::smoothing, 0, 100);
			}
			if (variables::aimbot::fovcheck) {
				menu_framework::slider(variables::menu::x + 70, variables::menu::y + 125, 125, render::fonts::button_font, "aim fov", variables::aimbot::fovcircle, 1, 300);
			}
			menu_framework::check_box(variables::menu::x + 10, variables::menu::y + 215, render::fonts::button_font, "remove punch", variables::aimbot::remove_punch);
		}
		break;
	case 2:
		menu_framework::selection_interface_2(variables::menu::x + 250, variables::menu::y + 20, variables::removals_selections, variables::removals_selected, variables::removals_opened);
		menu_framework::selection_interface_2(variables::menu::x + 300, variables::menu::y + 20, variables::misc_selections, variables::misc_selected, variables::misc_opened);
		menu_framework::check_box(variables::menu::x + 10, variables::menu::y + 20, render::fonts::button_font, "bhop", variables::bBhop);
		if (variables::bBhop) {
			menu_framework::selection_interface(variables::menu::x + 90, variables::menu::y + 20, variables::bhop_selections, variables::bhop, variables::bhop_selections_opened);
		}
		menu_framework::check_box(variables::menu::x + 10, variables::menu::y + 35, render::fonts::button_font, "fov", variables::bFov);
		if (variables::bFov && !variables::bhop_selections_opened) {
			menu_framework::slider(variables::menu::x + 50, variables::menu::y + 35, 125, render::fonts::button_font, "fov", variables::fov, 30, 160);
		}
		menu_framework::check_box(variables::menu::x + 10, variables::menu::y + 50, render::fonts::button_font, "radar", variables::bRadar);
		menu_framework::check_box(variables::menu::x + 10, variables::menu::y + 65, render::fonts::button_font, "no flash", variables::bNoFlash);
		if (variables::bNoFlash && !variables::bhop_selections_opened) {
			menu_framework::selection_interface(variables::menu::x + 90, variables::menu::y + 65, variables::no_flash_selections, variables::no_flash, variables::no_flash_selections_opened);
		}
		menu_framework::check_box(variables::menu::x + 10, variables::menu::y + 80, render::fonts::button_font, "no recoil", variables::bRcs);
		if (variables::bRcs) {
			menu_framework::selection_interface(variables::menu::x + 90, variables::menu::y + 80, variables::rcs_selections, variables::rcs_s, variables::rcs_opened);
		}
		menu_framework::check_box(variables::menu::x + 10, variables::menu::y + 95, render::fonts::button_font, "third person", variables::bTPS);
		break;
	case 3:
		//menu_framework::color_selection(variables::menu::x + 60, variables::menu::x + 80, variables::test_col, variables::test_bool);
		//menu_framework::selection_interface(variables::menu::x + 10, variables::menu::x + 50, variables::aim_type_selections, variables::aim_type, variables::aim_type_selections_opened);
		break;
	}
	if (variables::aim_type == 1 && variables::aimbot::smooth) {
		variables::aim_type == 0;
	}
	if (variables::aimbot::smooth && variables::aim_priority == 1) {
		variables::aimbot::sticky = true;
	}
	//menu_framework::menu_movement(variables::menu::x, variables::menu::y, variables::menu::w, variables::menu::h + 100);
}

void menu::toggle() {
	if (GetAsyncKeyState(VK_INSERT) & 1)
		variables::menu::opened = !variables::menu::opened;
}
