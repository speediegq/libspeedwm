/* libspeedwm - simple speedwm library
 * 
 * See LICENSE file for more information.
 */

#include <stdio.h>
#include <X11/Xlib.h>
#include "main.h"
#include "libspeedwm.h"

void
help() {
		fputs(NAME " - simple speedwm library\n\n"
				   "-- Arguments --\n"
				   "--rsig <signal>              Runs the specified signal.\n"
				   "--perform <action>           Performs the specified action.\n"
				   "--list-actions               Lists all the actions\n"
				   "--version                    Print " NAME " version\n"
				   "No arguments will print this help document.\n\n"
				   "-- Signals --\n"
				   "See speedwm-help -5 for a full list.\n\n"
				   "libspeedwm is licensed under the terms of the GNU General Public License version 3.0.\n"
				   "See https://speedie.gq/libspeedwm or https://codeberg.org/speedie/libspeedwm for more information.\n",
		stderr);

		return;
}

void
perform(char *args) {
		/* layouts
		 * tile
		 */
		if (!strcmp(args, "layout_setlayout_tile"))
				rsig("1");
		/* floating */
		if (!strcmp(args, "layout_setlayout_float"))
				rsig("2");
		/* monocle */
		if (!strcmp(args, "layout_setlayout_monocle"))
				rsig("3");
		/* grid */
		if (!strcmp(args, "layout_setlayout_grid"))
				rsig("4");
		/* deck */
		if (!strcmp(args, "layout_setlayout_deck"))
				rsig("5");
		/* centered master */
		if (!strcmp(args, "layout_setlayout_cm"))
				rsig("6");
		/* tatami */
		if (!strcmp(args, "layout_setlayout_tatami"))
				rsig("7");
		/* spiral */
		if (!strcmp(args, "layout_setlayout_spiral"))
				rsig("8");
		/* dwindle */
		if (!strcmp(args, "layout_setlayout_dwindle"))
				rsig("9");
		/* bottom stack */
		if (!strcmp(args, "layout_setlayout_bs"))
				rsig("10");
		/* horiz bottom stack */
		if (!strcmp(args, "layout_setlayout_hbs"))
				rsig("11");
		/* horiz grid */
		if (!strcmp(args, "layout_setlayout_hgrid"))
				rsig("12");
		/* dynamic grid */
		if (!strcmp(args, "layout_setlayout_dgrid"))
				rsig("13");
		/* custom */
		if (!strcmp(args, "layout_setlayout_custom")) {
				rsig("14");
		/* empty */
		} if (!strcmp(args, "layout_setlayout_empty"))
				rsig("113");

		/* set_s_layout */
		if (!strcmp(args, "layout_custom_express")) {
				rsig("14"); /* set layout to custom first, just in case because not doing so causes a crash for some reason, will fix in next speedwm version */
				rsig("15");
		}

		/* cycle up */
		if (!strcmp(args, "layout_cycle_up"))
				rsig("16");
		/* cycle down */
		if (!strcmp(args, "layout_cycle_down"))
				rsig("17");

       /* toggles
		*
		* toggle bar */
		if (!strcmp(args, "toggle_bar"))
				rsig("21");
		/* toggle tags */
		if (!strcmp(args, "toggle_bar_tags"))
				rsig("68");
		/* toggle empty tags */
		if (!strcmp(args, "toggle_bar_empty_tags"))
				rsig("69");

		/* toggle title */
		if (!strcmp(args, "toggle_bar_title"))
				rsig("77");
		/* toggle unsel title */
		if (!strcmp(args, "toggle_bar_unsel_title"))
				rsig("78");

		/* toggle layout indicator */
		if (!strcmp(args, "toggle_bar_ltindicator"))
				rsig("79");

		/* toggle status */
		if (!strcmp(args, "toggle_bar_status"))
				rsig("80");

		/* toggle float */
		if (!strcmp(args, "toggle_bar_float"))
				rsig("81");

		/* toggle sticky */
		if (!strcmp(args, "toggle_bar_sticky"))
				rsig("82");

		/* toggle icon */
		if (!strcmp(args, "toggle_bar_icon"))
				rsig("83");

		/* toggle bar padding */
		if (!strcmp(args, "toggle_bar_padding"))
				rsig("98");
		/* toggle vertical bar padding */
		if (!strcmp(args, "toggle_bar_padding_v"))
				rsig("96");
		/* toggle horizontal vertical bar padding */
		if (!strcmp(args, "toggle_bar_padding_h"))
				rsig("97");

		/* toggle systray */
		if (!strcmp(args, "toggle_bar_systray"))
				rsig("61");

		/* toggle client sticky */
		if (!strcmp(args, "toggle_client_sticky"))
				rsig("20");
		/* toggle client fullscreen */
		if (!strcmp(args, "toggle_client_fullscr"))
				rsig("22");
		/* toggle client fullscreen */
		if (!strcmp(args, "toggle_client_floating"))
				rsig("23");
		/* toggle client opacity */
		if (!strcmp(args, "toggle_client_opacity"))
				rsig("40");
		/* toggle client gaps */
		if (!strcmp(args, "toggle_client_gaps"))
				rsig("46");
		/* toggle client border */
		if (!strcmp(args, "toggle_client_border"))
				rsig("120");
		/* toggle client border */
		if (!strcmp(args, "toggle_client_single_border"))
				rsig("121");

		/* reset bar height */
		if (!strcmp(args, "reset_bar_height"))
				rsig("89");
		/* reset client gaps */
		if (!strcmp(args, "reset_client_gaps"))
				rsig("45");
		/* reset client gaps */
		if (!strcmp(args, "reset_client_gaps"))
				rsig("45");
		/* reset layout */
		if (!strcmp(args, "reset_layout"))
				rsig("59");
		/* reset mastercount */
		if (!strcmp(args, "reset_mcount"))
				rsig("60");
		/* reset mfact */
		if (!strcmp(args, "reset_mfact"))
				rsig("64");
		/* reset barpadding */
		if (!strcmp(args, "reset_bar_padding"))
				rsig("101");
		/* reset barpadding and gaps */
		if (!strcmp(args, "reset_bar_padding_gaps"))
				rsig("122");
		/* reset vertical barpadding */
		if (!strcmp(args, "reset_bar_padding_v"))
				rsig("99");
		/* reset horizontal barpadding */
		if (!strcmp(args, "reset_bar_padding_h"))
				rsig("100");

		/* rotate up */
		if (!strcmp(args, "tiling_rotate_up"))
				rsig("31");
		/* rotate down */
		if (!strcmp(args, "tiling_rotate_down"))
				rsig("32");

		/* rotate ltaxis up */
		if (!strcmp(args, "tiling_rotate_ltaxis_up"))
				rsig("104");
		/* rotate master up */
		if (!strcmp(args, "tiling_rotate_master_up"))
				rsig("105");
		/* rotate stack up */
		if (!strcmp(args, "tiling_rotate_stack_up"))
				rsig("106");
		/* rotate secondary stack up */
		if (!strcmp(args, "tiling_rotate_second_stack_up"))
				rsig("107");

		/* rotate ltaxis down */
		if (!strcmp(args, "tiling_rotate_ltaxis_down"))
				rsig("108");
		/* rotate master up */
		if (!strcmp(args, "tiling_rotate_master_down"))
				rsig("109");
		/* rotate stack up */
		if (!strcmp(args, "tiling_rotate_stack_down"))
				rsig("110");
		/* rotate secondary stack up */
		if (!strcmp(args, "tiling_rotate_second_stack_down"))
				rsig("111");

		/* mirror layout */
		if (!strcmp(args, "tiling_layout_mirror"))
				rsig("112");

		/* inc mcount */
		if (!strcmp(args, "tiling_mcount_inc"))
				rsig("33");
		/* dec mcount */
		if (!strcmp(args, "tiling_mcount_dec"))
				rsig("34");
		/* inc scount */
		if (!strcmp(args, "tiling_scount_inc"))
				rsig("102");
		/* dec scount */
		if (!strcmp(args, "tiling_scount_dec"))
				rsig("103");

		/* inc mfact */
		if (!strcmp(args, "tiling_mfact_inc"))
				rsig("18");
		/* dec mfact */
		if (!strcmp(args, "tiling_mfact_dec"))
				rsig("19");

		/* inc cfact */
		if (!strcmp(args, "tiling_cfact_inc"))
				rsig("41");
		/* dec cfact */
		if (!strcmp(args, "tiling_cfact_dec"))
				rsig("42");

		/* inc gaps */
		if (!strcmp(args, "tiling_gaps_inc"))
				rsig("47");
		/* dec gaps */
		if (!strcmp(args, "tiling_gaps_dec"))
				rsig("48");

		/* inc in gaps */
		if (!strcmp(args, "tiling_gaps_in_inc"))
				rsig("49");
		/* dec in gaps */
		if (!strcmp(args, "tiling_gaps_in_dec"))
				rsig("50");

		/* inc out gaps */
		if (!strcmp(args, "tiling_gaps_out_inc"))
				rsig("51");
		/* dec out gaps */
		if (!strcmp(args, "tiling_gaps_out_dec"))
				rsig("52");

		/* inc barheight */
		if (!strcmp(args, "bar_height_inc"))
				rsig("87");
		/* dec barheight */
		if (!strcmp(args, "bar_height_dec"))
				rsig("88");

		/* inc barpadding + gaps */
		if (!strcmp(args, "bar_padding_gaps_inc"))
				rsig("114");
		/* dec barpadding + gaps */
		if (!strcmp(args, "bar_padding_gaps_dec"))
				rsig("115");

		/* inc barpadding */
		if (!strcmp(args, "bar_padding_inc"))
				rsig("94");
		/* dec barpadding */
		if (!strcmp(args, "bar_padding_dec"))
				rsig("95");

		/* inc v barpadding */
		if (!strcmp(args, "bar_padding_inc_v"))
				rsig("90");
		/* dec v barpadding */
		if (!strcmp(args, "bar_padding_dec_v"))
				rsig("91");

		/* inc h barpadding */
		if (!strcmp(args, "bar_padding_inc_h"))
				rsig("92");
		/* dec h barpadding */
		if (!strcmp(args, "bar_padding_dec_h"))
				rsig("93");

		/* kill sel */
		if (!strcmp(args, "client_sig_kill"))
				rsig("30");
		/* kill unsel */
		if (!strcmp(args, "client_sig_unsel_kill"))
				rsig("53");

		/* show */
		if (!strcmp(args, "client_visibility_show"))
				rsig("28");
		/* hide */
		if (!strcmp(args, "client_visibility_hide"))
				rsig("29");
		/* show all */
		if (!strcmp(args, "client_visibility_show_all"))
				rsig("63");
		/* hide all */
		if (!strcmp(args, "client_visibility_hide_all"))
				rsig("62");

		/* zoom */
		if (!strcmp(args, "focus_zoom"))
				rsig("24");

		/* focus master */
		if (!strcmp(args, "focus_master"))
				rsig("35");

		/* focus visible next */
		if (!strcmp(args, "focus_visible_next"))
				rsig("36");
		/* focus visible prev */
		if (!strcmp(args, "focus_visible_prev"))
				rsig("37");
		/* focus hidden next */
		if (!strcmp(args, "focus_visible_next"))
				rsig("38");
		/* focus hidden prev */
		if (!strcmp(args, "focus_visible_prev"))
				rsig("39");

		/* focus next mon */
		if (!strcmp(args, "focus_mon_next"))
				rsig("54");
		/* focus prev mon */
		if (!strcmp(args, "focus_mon_prev"))
				rsig("55");

		/* show scratchpad */
		if (!strcmp(args, "sp_show"))
				rsig("56");
		/* hide scratchpad */
		if (!strcmp(args, "sp_hide"))
				rsig("57");
		/* remove scratchpad */
		if (!strcmp(args, "sp_remove"))
				rsig("58");

		/* tag left */
		if (!strcmp(args, "view_tag_left"))
				rsig("43");
		/* tag right */
		if (!strcmp(args, "view_tag_right"))
				rsig("44");
		/* tag left (skip vacant) */
		if (!strcmp(args, "view_tag_left_nv"))
				rsig("66");
		/* tag right (skip vacant) */
		if (!strcmp(args, "view_tag_right_nv"))
				rsig("67");

		/* reorganize tags */
		if (!strcmp(args, "tags_reorganize"))
				rsig("25");

		/* exit */
		if (!strcmp(args, "core_wm_exit"))
				rsig("26");
		/* restart */
		if (!strcmp(args, "core_wm_restart"))
				rsig("27");
		/* reload */
        if (!strcmp(args, "core_wm_reload"))
				rsig("65");
        
        /* toggle mark */
        if (!strcmp(args, "focus_toggle_mark"))
                rsig("116");
        if (!strcmp(args, "focus_swap_focus"))
                rsig("117");
        if (!strcmp(args, "focus_swap_client"))
                rsig("118");

        /* center */
        if (!strcmp(args, "client_center"))
                rsig("119");

		return;
}

void
listacts(void) {
		fputs("-- Layouts --\n"
		      "layout_setlayout_tile - Set the layout to Tile (Layout 1)\n"
		      "layout_setlayout_float - Set the layout to Floating (Layout 2)\n"
			  "layout_setlayout_monocle - Set the layout to Monocle (Layout 3)\n"
			  "layout_setlayout_grid - Set the layout to Grid (Layout 4)\n"
			  "layout_setlayout_deck - Set the layout to Deck (Layout 5)\n"
			  "layout_setlayout_cm - Set the layout to Centered Master (Layout 6)\n"
			  "layout_setlayout_tatami - Set the layout to Tatami (Layout 7)\n"
			  "layout_setlayout_spiral - Set the layout to Spiral (Layout 8)\n"
			  "layout_setlayout_dwindle - Set the layout to Dwindle (Layout 9)\n"
			  "layout_setlayout_bs - Set the layout to Bottom Stack (Layout 10)\n"
			  "layout_setlayout_hbs - Set the layout to Horizontal Bottom Stack (Layout 11)\n"
			  "layout_setlayout_hgrid - Set the layout to Horizontal Grid (Layout 12)\n"
			  "layout_setlayout_dgrid - Set the layout to Dynamic Grid (Layout 13)\n"
			  "layout_setlayout_custom - Set the layout to Custom (Layout 14)\n"
			  "layout_setlayout_empty - Set the layout to Empty (Layout 15)\n"
			  "\n"
			  "-- Misc layout --\n"
			  "layout_custom_express - Enter S expression for the custom layout (Layout 14)\n"
			  "layout_cycle_up - Cycle one layout up.\n"
			  "layout_cycle_down - Cycle one layout down.\n"
			  "\n"
			  "-- Toggle --\n"
			  "toggle_bar - Toggle the speedwm bar.\n"
			  "toggle_bar_tags - Toggle the tags in the speedwm bar.\n"
			  "toggle_bar_empty_tags - Toggle the tags that are empty in the speedwm bar.\n"
			  "toggle_bar_title - Toggle the title area in the speedwm bar.\n"
			  "toggle_bar_unsel_title - Toggle unselected title area in the speedwm bar.\n"
			  "toggle_bar_ltindicator - Toggle the layout indicator area in the speedwm bar.\n"
			  "toggle_bar_status - Toggle the status area in the speedwm bar.\n"
			  "toggle_bar_float - Toggle the floating window icon in the speedwm bar.\n"
			  "toggle_bar_sticky - Toggle the sticky window icon in the speedwm bar.\n"
			  "toggle_bar_icon - Toggle the window icon area in the speedwm bar.\n"
			  "toggle_bar_padding - Toggle the bar padding both vertically and horizontally.\n"
			  "toggle_bar_padding_h - Toggle the bar padding horizontally.\n"
			  "toggle_bar_padding_v - Toggle the bar padding vertically.\n"
			  "toggle_bar_systray - Toggle systray.\n"
			  "toggle_client_sticky - Toggle sticky status for a window.\n"
			  "toggle_client_fullscr - Toggle fullscreen status for a window.\n"
			  "toggle_client_floating - Toggle floating status for a window.\n"
			  "toggle_client_opacity - Toggle alpha for unfocused windows.\n"
			  "toggle_client_gaps - Toggle gaps for windows.\n"
              "toggle_client_border - Toggle border for the focused window.\n"
              "toggle_client_single_border - Toggle border for when there's a single window.\n"
			  "\n"
			  "-- Reset --\n"
			  "reset_bar_height - Reset bar height.\n"
			  "reset_bar_padding - Reset barpadding to default options defined on speedwm runtime.\n"
			  "reset_bar_padding_v - Reset vertical barpadding to default options defined on speedwm runtime.\n"
			  "reset_bar_padding_h - Reset horizontal barpadding to default options defined on speedwm runtime.\n"
              "reset_bar_padding_gaps - Reset bar padding and gaps.\n"
			  "reset_client_gaps - Reset gaps for windows.\n"
			  "reset_layout - Reset layout to top layout.\n"
			  "reset_mcount - Reset master count.\n"
			  "reset_mfact - Reset mfact.\n"
			  "\n"
			  "-- Tiling --\n"
			  "tiling_rotate_up - Rotate clients in the stack up.\n"
			  "tiling_rotate_down - Rotate clients in the stack down.\n"
			  "tiling_mcount_inc - Increase master count by 1.\n"
			  "tiling_mcount_dec - Decrease master count by 1.\n"
			  "tiling_scount_inc - Increase stack count by 1.\n"
			  "tiling_scount_dec - Decrease stack count by 1.\n"
			  "tiling_mfact_inc - Increase mfact by 0.05.\n"
			  "tiling_mfact_dec - Decrease mfact by 0.05.\n"
			  "tiling_cfact_inc - Increase cfact by 0.05.\n"
			  "tiling_cfact_dec - Decrease cfact by 0.05.\n"
			  "tiling_gaps_inc - Increase gaps by 1.\n"
			  "tiling_gaps_dec - Decrease gaps by 1.\n"
			  "tiling_gaps_in_inc - Increase inner gaps by 1.\n"
			  "tiling_gaps_in_dec - Decrease inner gaps by 1.\n"
			  "tiling_gaps_out_inc - Increase outer gaps by 1.\n"
			  "tiling_gaps_out_dec - Decrease outer gaps by 1.\n"
			  "tiling_rotate_ltaxis_up - Rotate forward in the layout axis.\n"
			  "tiling_rotate_master_up - Rotate forward in the master axis.\n"
			  "tiling_rotate_stack_up - Rotate forward in the stack axis.\n"
			  "tiling_rotate_second_stack_up - Rotate forward in the secondary stack axis.\n"
			  "tiling_layout_mirror - Mirror the layout.\n"
			  "\n"
			  "-- Client --\n"
			  "client_sig_kill - Kill the selected client.\n"
			  "client_sig_unsel_kill - Kill all unselected clients.\n"
              "client_center - Center the focused client.\n"
			  "client_visibility_show - Show the selected client.\n"
			  "client_visibility_hide - Hide the selected client.\n"
			  "client_visibility_show_all - Show all clients.\n"
			  "client_visibility_hide_all - Hide all clients.\n"
			  "\n"
			  "-- Bar --\n"
			  "bar_height_inc - Increase bar height by 1.\n"
			  "bar_height_dec - Decrease bar height by 1.\n"
			  "bar_padding_inc - Increase bar padding by 1.\n"
			  "bar_padding_dec - Decrease bar padding by 1.\n"
			  "bar_padding_inc_v - Increase vertical bar padding by 1.\n"
			  "bar_padding_dec_v - Decrease vertical bar padding by 1.\n"
			  "bar_padding_inc_h - Increase horizontal bar padding by 1.\n"
			  "bar_padding_dec_h - Decrease horizontal bar padding by 1.\n"
              "bar_padding_gaps_inc - Increase bar padding and gaps by 1.\n"
              "bar_padding_gaps_dec - Decrease bar padding and gaps by 1.\n"
			  "\n"
			  "-- Focus --\n"
			  "focus_zoom - Swap the focused stack with the other stack.\n"
			  "focus_master - Focus the master. If this was called before, focus will be returned to the previous window.\n"
			  "focus_visible_next - Focus the next visible window.\n"
			  "focus_visible_prev - Focus the previous visible window.\n"
			  "focus_hidden_next - Focus the next hidden window.\n"
			  "focus_hidden_prev - Focus the previous hidden window.\n"
			  "focus_mon_next - Focus the next monitor.\n"
			  "focus_mon_prev - Focus the previous monitor.\n"
              "focus_toggle_mark - (Un)mark the focused client.\n"
              "focus_swap_focus - Swap focus between the focused client and the marked client.\n"
              "focus_swap_client - Swap focused client with the marked client.\n"
			  "\n"
			  "-- Scratchpad --\n"
			  "sp_show - Show the scratchpad.\n"
			  "sp_hide - Hide the scratchpad.\n"
			  "sp_remove - Remove the scratchpad.\n"
			  "\n"
			  "-- View --\n"
			  "view_tag_left - View a tag to the left.\n"
			  "view_tag_right - View a tag to the right.\n"
			  "view_tag_left_nv - View a tag to the left skipping empty tags.\n"
			  "view_tag_right_nv - View a tag to the right skipping empty tags.\n"
			  "\n"
			  "-- Tags --\n"
			  "tags_reorganize - Reorganize tags, that is 1, 2, 4 becomes 1, 2, 3.\n"
			  "\n"
			  "-- Core --\n"
			  "core_wm_reload - Reload .Xresources options/speedwmrc.\n"
			  "core_wm_exit - Exit speedwm.\n"
			  "core_wm_restart - Restart speedwm.\n"
			  "",
		stderr);

		return;
		      
}

void
ver(void) {
		fputs(NAME " " VER "\n", stderr);
		return;
}

void
rsig(char *signum) {
		char sigtext[] = "#cmd:";
		Display *dp;

		dp = XOpenDisplay(NULL);

		XStoreName(dp, RootWindow(dp, DefaultScreen(dp)), strcat(sigtext, signum));
		XCloseDisplay(dp);

		return;
}

int
main(int argc, char *argv[]) {
		/* if we have no arguments, list the arguments */
		if (argc < 2) {
				help();
				return 1;
		} else if (argc > 3) {
				printf("Error: Too many arguments specified.\n");
				return 1;
		}

		/* run signum */
        if (!strcmp(argv[1], "--rsig")) {
				char *signum = argv[2];

				if (argc < 3)
						printf("You must specify a signal to send.\n");
				else {
						rsig(signum);
				}
		/* perform */
		} else if (!strcmp(argv[1], "--perform")) {
				if (argc < 3)
						printf("You must specify an action. Do --list-actions to see a list of possible actions\n");
				else {
						char *args = argv[2];
						perform(args);
				}
		/* list actions */
		} else if (!strcmp(argv[1], "--list-actions"))
				listacts();
		/* version */
		else if (!strcmp(argv[1], "--version"))
				ver();
		else if (!strcmp(argv[1], "--help"))
				help();
		else {
				printf("Invalid argument: %s. Run --help for a list of valid arguments.\n", argv[1]);
				return 1;
		}
}
