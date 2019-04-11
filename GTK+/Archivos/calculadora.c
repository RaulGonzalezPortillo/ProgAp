#include <gtk/gtk.h>
#include <string.h>

void DetenerApp(GtkWidget *window, gpointer data);
GtkWidget *AddButton(GtkWidget *theBox, const gchar *buttonText, gpointer CallBackFunction, GtkWidget *EntryBox);
void ButtonClicked(GtkButton *button, gpointer data);

gint main ( gint argc, gchar *argv[])
{

  GtkWidget *ventana;
  GtkWidget *boton;
  GtkWidget *cajah;
  GtkWidget *cajav;
  GtkWidget *cajae;

  gtk_init(&argc, &argv);

  ventana = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_container_border_width(GTK_CONTAINER(ventana),5);

  cajav = gtk_vbox_new(TRUE,5);
  
  cajae = gtk_entry_new();
  gtk_box_pack_start(GTK_BOX(cajav),cajae,TRUE,TRUE,5);
  
  cajah = gtk_hbox_new(TRUE,5);
  
  boton = AddButton (cajah, "1", ButtonClicked, cajae);
  gtk_box_pack_start(GTK_BOX(cajav),cajah,TRUE,TRUE,5);

  gtk_signal_connect(GTK_OBJECT(ventana),"destroy",GTK_SIGNAL_FUNC(DetenerApp),NULL);
  gtk_container_add(GTK_CONTAINER(ventana),cajav);
  gtk_widget_show_all(ventana);
  gtk_main();
  return 0;
}

void DetenerApp(GtkWidget *window, gpointer data)
{
  gtk_main_quit();
}

GtkWidget *AddButton(GtkWidget *theBox, const gchar *buttonText, gpointer CallBackFunction, GtkWidget *EntryBox)
{
  GtkWidget *button;
  button = gtk_button_new_with_label(buttonText);
  gtk_box_pack_start(GTK_BOX(theBox),button,FALSE,TRUE,0);
  gtk_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(CallBackFunction),EntryBox);
  gtk_widget_show(button);
  return button;
}

void ButtonClicked(GtkButton *button, gpointer data)
{
  gtk_entry_set_text(GTK_ENTRY(data),"Hola Mundo");
}
