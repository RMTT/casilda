#include <gtk/gtk.h>
#include "casilda-compositor.h"

static void
activate (GtkApplication         *app,
          G_GNUC_UNUSED gpointer  user_data)
{
  CasildaCompositor *compositor;
  GtkWidget *window;
  g_autofree char *socket = NULL;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Compositor");
  gtk_window_set_default_size (GTK_WINDOW (window), 800, 600);

  socket = g_build_path (G_DIR_SEPARATOR_S, g_get_tmp_dir (),
                         "casilda-example.sock", NULL);
  compositor = casilda_compositor_new (socket);
  gtk_window_set_child (GTK_WINDOW (window), GTK_WIDGET (compositor));
  gtk_window_present (GTK_WINDOW (window));
}

int
main (int    argc,
      char **argv)
{
  g_autoptr(GtkApplication) app = NULL;

  app = gtk_application_new ("org.gnome.casilda.compositor", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);

  return g_application_run (G_APPLICATION (app), argc, argv);
}
