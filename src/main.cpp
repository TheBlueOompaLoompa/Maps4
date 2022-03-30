/* main.c
 *
 * Copyright 2022 BlueOompaLoompa
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <adwaita.h>

static void
activate_cb (GtkApplication *app)
{
	AdwApplicationWindow *window = (AdwApplicationWindow*)adw_application_window_new (app);
	GtkWidget *root = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	GtkWidget *label = gtk_label_new ("Hello World");

	AdwHeaderBar *headerbar = (AdwHeaderBar*)adw_header_bar_new();
	adw_header_bar_set_title_widget(headerbar, gtk_label_new("Maps"));

	gtk_box_append(GTK_BOX(root), GTK_WIDGET(headerbar));
	gtk_box_append(GTK_BOX(root), label);

	gtk_window_set_decorated((GtkWindow*)window, true);
	gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);
	adw_application_window_set_content(window, root);
	gtk_window_present (GTK_WINDOW (window));
}

int
main (int   argc,
      char *argv[])
{
  g_autoptr (AdwApplication) app = NULL;

  app = adw_application_new ("org.theblueoompaloompa.Maps4", G_APPLICATION_FLAGS_NONE);

  g_signal_connect (app, "activate", G_CALLBACK (activate_cb), NULL);

  return g_application_run (G_APPLICATION (app), argc, argv);
}

