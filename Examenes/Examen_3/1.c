#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct def_Datos
{
  GtkWidget *Edad;
  GtkWidget *Peso;
  GtkWidget *Zona[5];
  int Genero;
} TipoDatos;

void DetenerApp (GtkWidget *window, gpointer data);
void ClickHombre (GtkToggleButton *button, gpointer data);
void ClickMujer (GtkToggleButton *button, gpointer data);
void ClickCalcular (GtkButton *button, gpointer data);

gint main (gint argc, gchar *argv [])
{
  int i, j, k;
  GtkWidget *Ventana, *CajaV, *CajaH [11], *EntradaEdad, *EntradaPeso, *Texto, *BotonHombre, *BotonMujer, *BotonCalcular;
  TipoDatos Datos;
  Datos.Genero = 1;
  char TextoTemp [10], porciento = '%';
  gtk_init (&argc, &argv);
  Ventana = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (Ventana), "Zonas Cardiacas");
  gtk_container_set_border_width (GTK_CONTAINER (Ventana), 10);
  CajaV = gtk_vbox_new (TRUE, 5);
  for (i = 0; i < 11; i++)
    {
      CajaH [i] = gtk_hbox_new (TRUE, 5);
    }
  Texto = gtk_label_new ("Edad:");
  EntradaEdad = gtk_entry_new ();
  Datos.Edad = EntradaEdad;
  gtk_box_pack_start (GTK_BOX (CajaH [0]), Texto, TRUE, TRUE, 0);
  gtk_box_pack_start (GTK_BOX (CajaH [0]), EntradaEdad, TRUE, TRUE, 0);
  Texto = gtk_label_new ("Peso (libras):");
  EntradaPeso = gtk_entry_new ();
  Datos.Peso = EntradaPeso;
  gtk_box_pack_start (GTK_BOX (CajaH [1]), Texto, TRUE, TRUE, 0);
  gtk_box_pack_start (GTK_BOX (CajaH [1]), EntradaPeso, TRUE, TRUE, 0);
  Texto = gtk_label_new ("");
  BotonHombre = gtk_radio_button_new_with_label (NULL, "Hombre");
  gtk_signal_connect (GTK_OBJECT (BotonHombre), "toggled", GTK_SIGNAL_FUNC (ClickHombre), &Datos);
  gtk_box_pack_start (GTK_BOX (CajaH [2]), Texto, TRUE, TRUE, 0);
  gtk_box_pack_start (GTK_BOX (CajaH [2]), BotonHombre, TRUE, TRUE, 0);
  Texto = gtk_label_new ("");
  BotonMujer = gtk_radio_button_new_with_label (gtk_radio_button_get_group (GTK_RADIO_BUTTON (BotonHombre)), "Mujer");
  gtk_signal_connect (GTK_OBJECT (BotonMujer), "toggled", GTK_SIGNAL_FUNC (ClickMujer), &Datos);
  gtk_box_pack_start (GTK_BOX (CajaH [3]), Texto, TRUE, TRUE, 0);
  gtk_box_pack_start (GTK_BOX (CajaH [3]), BotonMujer, TRUE, TRUE, 0);
  Texto = gtk_label_new ("");
  BotonCalcular = gtk_button_new_with_label ("Calcular");
  gtk_signal_connect (GTK_OBJECT (BotonCalcular), "clicked", GTK_SIGNAL_FUNC (ClickCalcular), &Datos);
  gtk_box_pack_start (GTK_BOX (CajaH [4]), BotonCalcular, TRUE, TRUE, 0);
  gtk_box_pack_start (GTK_BOX (CajaH [4]), Texto, TRUE, TRUE, 0);
  Texto = gtk_label_new ("Zonas");
  gtk_box_pack_start (GTK_BOX (CajaH [5]), Texto, TRUE, TRUE, 0);
  j = 50;
  k = 6;
  for (i = 0; i < 5; i++)
    {
      Texto = gtk_label_new ("");
      gtk_box_pack_start (GTK_BOX (CajaH [k]), Texto, TRUE, TRUE, 0);
      sprintf (TextoTemp, "Zona %d", i + 1);
      Texto = gtk_label_new (TextoTemp);
      gtk_box_pack_start (GTK_BOX (CajaH [k]), Texto, TRUE, TRUE, 0);
      sprintf (TextoTemp, "%d%c - %d%c", j, porciento, j + 10, porciento);
      Texto = gtk_label_new (TextoTemp);
      gtk_box_pack_start (GTK_BOX (CajaH [k]), Texto, TRUE, TRUE, 0);
      Texto = gtk_label_new ("0 - 0 ppm");
      Datos.Zona [i] = Texto;
      gtk_box_pack_start (GTK_BOX (CajaH [k]), Datos.Zona [i], TRUE, TRUE, 0);
      Texto = gtk_label_new ("");
      gtk_box_pack_start (GTK_BOX (CajaH [k]), Texto, TRUE, TRUE, 0);
      j += 10;
      k++;
    }
  for (i = 0; i < 11; i++)
    {
      gtk_box_pack_start (GTK_BOX (CajaV), CajaH [i], TRUE, TRUE, 0);
    }
  gtk_signal_connect (GTK_OBJECT (Ventana), "destroy", GTK_SIGNAL_FUNC (DetenerApp), NULL);
  gtk_container_add (GTK_CONTAINER (Ventana), CajaV);
  gtk_widget_show_all (Ventana);
  gtk_main();
  return 0;
}

void DetenerApp (GtkWidget *window, gpointer data)
{
  gtk_main_quit ();
}

void ClickHombre (GtkToggleButton *button, gpointer data)
{
  TipoDatos *Datos = (TipoDatos *)data;
  Datos -> Genero = 1;
}

void ClickMujer (GtkToggleButton *button, gpointer data)
{
  TipoDatos *Datos = (TipoDatos *)data;
  Datos -> Genero = 0;
}

void ClickCalcular (GtkButton *button, gpointer data)
{
  TipoDatos *Datos = (TipoDatos *)data;
  int Edad, i;
  float Peso, Maximo, Porcentaje, Maximos [6];
  char TempTexto [50];
  const gchar *EntradaEdad, *EntradaPeso;
  EntradaEdad = gtk_entry_get_text (GTK_ENTRY (Datos -> Edad));
  sscanf (EntradaEdad, "%d", &Edad);
  EntradaPeso = gtk_entry_get_text (GTK_ENTRY (Datos -> Peso));
  sscanf (EntradaPeso, "%f", &Peso);
  Porcentaje = 0.5;
  if (Datos -> Genero == 1)
    {
      for (i = 0; i < 6; i++)
	{
	  Maximo = (210 - (Edad / 2) - (Peso * 0.05) + 4) * Porcentaje;
	  Porcentaje += .1;
	  Maximos [i] = Maximo;
	}
    }
  else
    {
      for (i = 0; i < 6; i++)
	{
	  Maximo = (210 - (Edad / 2) - (Peso * 0.01)) * Porcentaje;
	  Porcentaje += .1;
	  Maximos [i] = Maximo;
	}
    }
  for (i = 0; i < 5; i++)
    {
      sprintf (TempTexto, "%.0f - %.0f ppm", Maximos [i], Maximos [i + 1]);
      gtk_label_set_text(GTK_LABEL (Datos -> Zona [i]), TempTexto);
    }
}
