#include <gtk/gtk.h>
#include <string.h>

gint main ( gint argc, gchar *argv[])
{
  GtkWidget *ventana;
  GtkWidget *cajav;
  GtkWidget *cajah;
  GtkWidget *cajae;
  GtkWidget *boton1;
  GtkWidget *boton2;

  gtk_init(&argc, &argv);

  ventana = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_container_border_width(GTK_CONTAINER(ventana),5);

  cajav = gtk_vbox_new (TRUE, 5);
  cajae = gtk_entry_new ();
  cajah = gtk_hbox_new (TRUE, 5);
  boton1 = gtk_button_new_with_label ("+");
  boton2 = gtk_button_new_with_label (">");

  gtk_box_pack_start (GTK_BOX (cajah), boton1, TRUE, TRUE, 0);
  gtk_widget_show (boton1);
  gtk_box_pack_start (GTK_BOX (cajah), cajae, TRUE, TRUE, 0);
  gtk_widget_show (cajae);
  gtk_box_pack_start (GTK_BOX (cajah), boton2, TRUE, TRUE, 0);
  gtk_widget_show (boton2);

  gtk_box_pack_start (GTK_BOX (cajav),cajah,TRUE,TRUE,5);

  gtk_container_add(GTK_CONTAINER(ventana),cajav);

  gtk_widget_show_all(ventana);
  
  gtk_main();

  return 0;

}
