#include <gtk/gtk.h>

void hello(GtkWidget *widget, gpointer data)
{
  g_print("Hola Perro Mundo \n"); //Imprime texto en la terminal
}


void destroy(GtkWidget *widget, gpointer data) //Este encabezado es el mismo siempre
{
  gtk_main_quit(); //Este es como un exit 0; terminará por completo 
}

int main(int argc, char *argv[])
{
  GtkWidget *window;
  GtkWidget *button;


  gtk_init(&argc, &argv); //Inicialización de GTK

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL); //Creamos una ventana

  gtk_signal_connect(GTK_OBJECT(window),"destroy", GTK_SIGNAL_FUNC(destroy), NULL); //"Conectamos" al boton cerrar con la función destroy (SUPER IMPORTANTE)
  //PARAMETROS: Obtejo a conectar, Nombre de la señal, Función a la cual se conecta, NULL
  gtk_container_set_border_width(GTK_CONTAINER(window),10); //Establecemos un margen a la ventana de 10px
  //PARAMETROS: ¿De que contenedor hablamos?, 10 pixeles
  button=gtk_button_new_with_label("Hola Mundo"); //Creamos un nuevo boton con texto / etiqueta
  //PARAMETROS: "Texto a mostrar en el botón"
  gtk_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(hello), NULL); //Conectamos al botón con la función hello
  
  gtk_container_add(GTK_CONTAINER(window),button); //Añadimos el botón a la ventana
  //PARAMETROS: ¿A donde lo quieres insertar?, ¿Que quieres insertar?
  gtk_widget_show(button); //Mostramos el botón
  gtk_widget_show(window); //Mostramos la ventana
  //Primero mostramos lo de adentro de la ventana y luego la ventana, para evitar fallasa visuales

  gtk_main();

  return(0);
}
