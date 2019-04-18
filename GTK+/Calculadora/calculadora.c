#include <gtk/gtk.h>
#include <string.h>

void DetenerApp (GtkWidget *window, gpointer data);
GtkWidget *AgregarBoton (GtkWidget *theBox, const gchar *buttonText, gpointer CallBackFunction, GtkWidget *EntryBox);
void ClickNumero (GtkButton *button, gpointer data);
void ClickC(GtkButton *button, gpointer data);
void ClickMasMenos(GtkButton *button, gpointer data);

gint main ( gint argc, gchar *argv[])
{

  GtkWidget *ventana;
  GtkWidget *boton;
  GtkWidget *cajah, *subcajah;
  GtkWidget *cajav;
  GtkWidget *cajae;

  gtk_init(&argc, &argv);

  ventana = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_container_border_width(GTK_CONTAINER(ventana),5);

  cajav = gtk_vbox_new(TRUE,0);

  cajae = gtk_entry_new();
  gtk_box_pack_start(GTK_BOX(cajav),cajae,TRUE,TRUE,5);

  cajah = gtk_hbox_new(TRUE,5);
  boton = AgregarBoton (cajah, "C", ClickC, cajae);
  boton = AgregarBoton (cajah, "+/-", ClickMasMenos, cajae);
  boton = AgregarBoton (cajah, "%", ClickNumero, cajae);
  boton = AgregarBoton (cajah, "/", ClickNumero, cajae);
  gtk_box_pack_start(GTK_BOX(cajav),cajah,TRUE,TRUE,5);

  cajah = gtk_hbox_new(TRUE,5);
  boton = AgregarBoton (cajah, "7", ClickNumero, cajae);
  boton = AgregarBoton (cajah, "8", ClickNumero, cajae);
  boton = AgregarBoton (cajah, "9", ClickNumero, cajae);
  boton = AgregarBoton (cajah, "x", ClickNumero, cajae);
  gtk_box_pack_start(GTK_BOX(cajav),cajah,TRUE,TRUE,5);

  cajah = gtk_hbox_new(TRUE,5);
  boton = AgregarBoton (cajah, "4", ClickNumero, cajae);
  boton = AgregarBoton (cajah, "5", ClickNumero, cajae);
  boton = AgregarBoton (cajah, "6", ClickNumero, cajae);
  boton = AgregarBoton (cajah, "-", ClickNumero, cajae);
  gtk_box_pack_start(GTK_BOX(cajav),cajah,TRUE,TRUE,5);

  cajah = gtk_hbox_new(TRUE,5);
  boton = AgregarBoton (cajah, "1", ClickNumero, cajae);
  boton = AgregarBoton (cajah, "2", ClickNumero, cajae);
  boton = AgregarBoton (cajah, "3", ClickNumero, cajae);
  boton = AgregarBoton (cajah, "+", ClickNumero, cajae);
  gtk_box_pack_start(GTK_BOX(cajav),cajah,TRUE,TRUE,5);

  cajah = gtk_hbox_new(TRUE,5);
  subcajah = gtk_hbox_new(TRUE,5);
  boton = AgregarBoton (subcajah, "0", ClickNumero, cajae);
  gtk_box_pack_start(GTK_BOX(cajah),subcajah,TRUE,TRUE,0);
  subcajah = gtk_hbox_new(TRUE,5);
  boton = AgregarBoton (subcajah, ".", ClickNumero, cajae);
  boton = AgregarBoton (subcajah, "=", ClickNumero, cajae);
  gtk_box_pack_start(GTK_BOX(cajah),subcajah,TRUE,TRUE,0);
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

GtkWidget *AgregarBoton(GtkWidget *theBox, const gchar *buttonText, gpointer CallBackFunction, GtkWidget *EntryBox)
{
  GtkWidget *button;
  button = gtk_button_new_with_label(buttonText);
  gtk_box_pack_start(GTK_BOX(theBox),button,FALSE,TRUE,0);
  gtk_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(CallBackFunction),EntryBox);
  gtk_widget_show(button);
  return button;
}

void ClickNumero(GtkButton *button, gpointer data)
{
  char Numero [3];
  strcpy (Numero,gtk_button_get_label (button));
  gtk_entry_append_text(GTK_ENTRY(data), Numero);
}

void ClickC(GtkButton *button, gpointer data)
{
  gtk_entry_set_text(GTK_ENTRY(data), "");
}

void ClickMasMenos(GtkButton *button, gpointer data)
{
  gtk_entry_prepend_text(GTK_ENTRY(data), "-(");
  gtk_entry_append_text(GTK_ENTRY(data), ")");
}
