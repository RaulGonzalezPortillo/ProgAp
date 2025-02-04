#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct node{
  GtkWidget *entrybox;
  float Numero;
  char Operacion [3];
} Nodo;

void DetenerApp (GtkWidget *window, gpointer data);
GtkWidget *AgregarBoton (GtkWidget *theBox, const gchar *buttonText, gpointer CallBackFunction, GtkWidget *EntryBox);
GtkWidget *AgregarBotonNaranja (GtkWidget *theBox, const gchar *buttonText, gpointer CallBackFunction, GtkWidget *EntryBox);
GtkWidget *AgregarBotonGris(GtkWidget *theBox, const gchar *buttonText, gpointer CallBackFunction, GtkWidget *EntryBox);
void ClickNumero (GtkButton *button, gpointer data);
void ClickOperacion(GtkButton *button, gpointer data);
void ClickCE(GtkButton *button, gpointer data);
void ClickC(GtkButton *button, gpointer data);
void ClickResultado(GtkButton *button, gpointer data);
void Cambiaopcion1 (GtkToggleButton *button, gpointer data);
void HacerNada (GtkToggleButton *button, gpointer data);


gint main ( gint argc, gchar *argv[])
{

  GtkWidget *ventana;
  GtkWidget *boton;
  GtkWidget *cajah, *subcajah, *grancajah;
  GtkWidget *cajav, *cajav2, *grancajav;
  GtkWidget *cajae;
  GtkWidget *root_menu;
  GtkWidget *menu_bar;
  GtkWidget *op1, *op2, *op3;
  GtkWidget *menu;
  GtkWidget *rb1, *rb2;

  gtk_init(&argc, &argv);

  ventana = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_container_border_width(GTK_CONTAINER(ventana), 0);

  grancajah = gtk_hbox_new (FALSE, 0);
  grancajav = gtk_vbox_new (FALSE, 0);
  cajav = gtk_vbox_new(TRUE,0);
  cajav2 = gtk_vbox_new(FALSE,0);
  
  cajae = gtk_entry_new();
  
  menu_bar = gtk_menu_bar_new ();

  menu = gtk_menu_new ();
  op1 = gtk_menu_item_new_with_label ("Limpiar");
  op2 = gtk_menu_item_new_with_label ("Salir");

  gtk_signal_connect (GTK_OBJECT (op1), "activate", GTK_SIGNAL_FUNC (ClickCE), cajae);
  gtk_signal_connect (GTK_OBJECT (op2), "activate", GTK_SIGNAL_FUNC (DetenerApp), NULL);

  gtk_menu_append (GTK_MENU (menu), op1);
  gtk_menu_append (GTK_MENU (menu), op2);

  root_menu = gtk_menu_item_new_with_label ("Calculadora");

  gtk_menu_item_set_submenu (GTK_MENU_ITEM (root_menu), menu);
  
  gtk_menu_bar_append (GTK_MENU_BAR (menu_bar), root_menu);

  menu = gtk_menu_new ();
  op1 = gtk_menu_item_new_with_label ("Leer");
  op2 = gtk_menu_item_new_with_label ("Guardar");
  op3 = gtk_menu_item_new_with_label ("Nuevo");

  gtk_menu_append (GTK_MENU (menu), op1);
  gtk_menu_append (GTK_MENU (menu), op2);
  gtk_menu_append (GTK_MENU (menu), op3);

  gtk_signal_connect (GTK_OBJECT (op1), "activate", GTK_SIGNAL_FUNC (HacerNada), NULL);
  gtk_signal_connect (GTK_OBJECT (op2), "activate", GTK_SIGNAL_FUNC (HacerNada), NULL);
  gtk_signal_connect (GTK_OBJECT (op3), "activate", GTK_SIGNAL_FUNC (HacerNada), NULL);

  root_menu = gtk_menu_item_new_with_label ("Archivo");

  gtk_menu_item_set_submenu (GTK_MENU_ITEM (root_menu), menu);

  gtk_menu_bar_append (GTK_MENU_BAR (menu_bar), root_menu);

  root_menu = gtk_menu_item_new_with_label ("Salir");
  gtk_signal_connect (GTK_OBJECT (root_menu), "activate", GTK_SIGNAL_FUNC (DetenerApp), NULL);
  gtk_menu_bar_append (GTK_MENU_BAR (menu_bar), root_menu);

  gtk_box_pack_start(GTK_BOX(grancajav),menu_bar,FALSE,FALSE,0);
  
  gtk_box_pack_start(GTK_BOX(cajav),cajae,TRUE,TRUE,5);

  cajah = gtk_hbox_new(TRUE,5);
  boton = AgregarBotonGris (cajah, "CE", ClickCE, cajae);
  boton = AgregarBotonGris (cajah, "C", ClickC, cajae);
  boton = AgregarBotonGris (cajah, "%", ClickOperacion, cajae);
  boton = AgregarBotonNaranja (cajah, "/", ClickOperacion, cajae);
  gtk_box_pack_start(GTK_BOX(cajav),cajah,TRUE,TRUE,5);

  cajah = gtk_hbox_new(TRUE,5);
  boton = AgregarBoton (cajah, "7", ClickNumero, cajae);
  boton = AgregarBoton (cajah, "8", ClickNumero, cajae);
  boton = AgregarBoton (cajah, "9", ClickNumero, cajae);
  boton = AgregarBotonNaranja (cajah, "x", ClickOperacion, cajae);
  gtk_box_pack_start(GTK_BOX(cajav),cajah,TRUE,TRUE,5);

  cajah = gtk_hbox_new(TRUE,5);
  boton = AgregarBoton (cajah, "4", ClickNumero, cajae);
  boton = AgregarBoton (cajah, "5", ClickNumero, cajae);
  boton = AgregarBoton (cajah, "6", ClickNumero, cajae);
  boton = AgregarBotonNaranja (cajah, "-", ClickOperacion, cajae);
  gtk_box_pack_start(GTK_BOX(cajav),cajah,TRUE,TRUE,5);

  cajah = gtk_hbox_new(TRUE,5);
  boton = AgregarBoton (cajah, "1", ClickNumero, cajae);
  boton = AgregarBoton (cajah, "2", ClickNumero, cajae);
  boton = AgregarBoton (cajah, "3", ClickNumero, cajae);
  boton = AgregarBotonNaranja (cajah, "+", ClickOperacion, cajae);
  gtk_box_pack_start(GTK_BOX(cajav),cajah,TRUE,TRUE,5);

  gtk_box_pack_start (GTK_BOX (grancajah), cajav, TRUE, TRUE, 10);
  
  cajah = gtk_hbox_new(TRUE,5);
  subcajah = gtk_hbox_new(TRUE,5);
  boton = AgregarBoton (subcajah, "0", ClickNumero, cajae);
  gtk_box_pack_start(GTK_BOX(cajah),subcajah,TRUE,TRUE,0);
  subcajah = gtk_hbox_new(TRUE,5);
  boton = AgregarBoton (subcajah, ".", ClickNumero, cajae);
  boton = AgregarBotonNaranja (subcajah, "=", ClickResultado, cajae);
  gtk_box_pack_start(GTK_BOX(cajah),subcajah,TRUE,TRUE,0);
  gtk_box_pack_start(GTK_BOX(cajav),cajah,TRUE,TRUE,5);

  rb1 = gtk_radio_button_new_with_label (NULL, "Opción 1: ");
  gtk_box_pack_start (GTK_BOX (cajav2), rb1, FALSE, FALSE, 0);
  gtk_signal_connect (GTK_OBJECT (rb1), "toggled", GTK_SIGNAL_FUNC (Cambiaopcion1), "1"); 

  rb2 = gtk_radio_button_new_with_label (gtk_radio_button_get_group (GTK_RADIO_BUTTON (rb1)), "Opción 2: ");
  gtk_box_pack_start (GTK_BOX (cajav2), rb2, FALSE, FALSE, 0);
  gtk_signal_connect (GTK_OBJECT (rb2), "toggled", GTK_SIGNAL_FUNC (Cambiaopcion1), "2");

  rb2 = gtk_radio_button_new_with_label (gtk_radio_button_get_group (GTK_RADIO_BUTTON (rb1)), "Opción 3: ");
  gtk_box_pack_start (GTK_BOX (cajav2), rb2, FALSE, FALSE, 0);
  gtk_signal_connect (GTK_OBJECT (rb2), "toggled", GTK_SIGNAL_FUNC (Cambiaopcion1), "3");

  gtk_box_pack_start (GTK_BOX (grancajah), cajav2, TRUE, TRUE, 15);
  
  gtk_box_pack_start (GTK_BOX (grancajav), grancajah, TRUE, TRUE, 5);
  
  gtk_signal_connect(GTK_OBJECT(ventana),"destroy",GTK_SIGNAL_FUNC(DetenerApp),NULL);
  
  gtk_container_add(GTK_CONTAINER(ventana), grancajav);
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

GtkWidget *AgregarBotonNaranja(GtkWidget *theBox, const gchar *buttonText, gpointer CallBackFunction, GtkWidget *EntryBox)
{
  GtkWidget *button;
  GdkColor color;
  gdk_color_parse ("#F19936", &color);
  button = gtk_button_new_with_label(buttonText);
  gtk_widget_modify_bg (button, GTK_STATE_NORMAL, &color);
  gtk_widget_modify_bg (button, GTK_STATE_PRELIGHT, &color);
  gtk_box_pack_start(GTK_BOX(theBox),button,FALSE,TRUE,0);
  gtk_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(CallBackFunction),EntryBox);
  gtk_widget_show(button);
  return button;
}

GtkWidget *AgregarBotonGris(GtkWidget *theBox, const gchar *buttonText, gpointer CallBackFunction, GtkWidget *EntryBox)
{
  GtkWidget *button;
  GdkColor color;
  gdk_color_parse ("#727272", &color);
  button = gtk_button_new_with_label(buttonText);
  gtk_widget_modify_bg (button, GTK_STATE_NORMAL, &color);
  gtk_widget_modify_bg (button, GTK_STATE_PRELIGHT, &color);
  gtk_box_pack_start(GTK_BOX(theBox),button,FALSE,TRUE,0);
  gtk_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(CallBackFunction),EntryBox);
  gtk_widget_show(button);
  return button;
}

void ClickNumero(GtkButton *button, gpointer data)
{
  char Numero[3];
  strcpy (Numero, gtk_button_get_label (button));
  gtk_entry_append_text(GTK_ENTRY(data), Numero);
}

void ClickOperacion(GtkButton *button, gpointer data)
{
  Nodo *datos=(Nodo *)data;
  char Numero [10];
  const gchar *Entrada;
  Entrada = gtk_entry_get_text (GTK_ENTRY (data));
  strcpy (Numero, Entrada);
  datos -> Numero = atof (Numero);
  strcpy (datos -> Operacion, gtk_button_get_label (button));
  gtk_entry_set_text(GTK_ENTRY(data), "");
}

void ClickCE(GtkButton *button, gpointer data)
{
  gtk_entry_set_text(GTK_ENTRY(data), "");
}

void ClickC(GtkButton *button, gpointer data)
{
  char NuevaEntrada [50];
  const gchar *Entrada;
  Entrada = gtk_entry_get_text (GTK_ENTRY (data));
  strcpy (NuevaEntrada, Entrada);
  NuevaEntrada [strlen (NuevaEntrada) - 1] = '\0';
  gtk_entry_set_text (GTK_ENTRY (data), NuevaEntrada);
}

void ClickResultado(GtkButton *button, gpointer data)
{
  Nodo *datos=(Nodo *)data;
  float Numero2, Resultado;
  int Num1, Num2;
  char CadenaResultado [20], TempEntrada [20];
  const gchar *Entrada;
  Entrada = gtk_entry_get_text (GTK_ENTRY (data));
  strcpy (TempEntrada, Entrada);
  Numero2 = atof (TempEntrada);
  switch (datos -> Operacion [0])
  {
    case '+':
    Resultado = datos -> Numero + Numero2;
    break;
    case '-':
    Resultado = datos -> Numero - Numero2;
    break;
    case '/':
    Resultado = datos -> Numero / Numero2;
    break;
    case 'x':
    Resultado = datos -> Numero * Numero2;
    break;
    case '%':
    Num1 = datos -> Numero;
    Num2 = Numero2;
    Resultado = Num1 % Num2;
    break;
  }
  sprintf (CadenaResultado, "%.2f", Resultado);
  gtk_entry_set_text (GTK_ENTRY (data), CadenaResultado);
}

void Cambiaopcion1 (GtkToggleButton *button, gpointer data)
{
  char *cad = (char *)data;
  if (gtk_toggle_button_get_active (button))
    g_print ("Botón seleccionado %s\n", cad);
}

void HacerNada (GtkToggleButton *button, gpointer data)
{
}
