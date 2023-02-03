#include <gtk/gtk.h>
#include <stdio.h>

typedef struct {
  GtkWidget *window;
  GtkWidget *btn_download;
  GtkWidget *entry_main;
} widgets_t;

int main( int argc, char *argv[]){
   
  GtkBuilder *builder;

  widgets_t *widgets = g_slice_new(widgets_t);

  gtk_init (&argc, &argv);

  builder = gtk_builder_new();
  gtk_builder_add_from_file(builder, "glade/GYVD.glade", NULL);

  widgets->window = GTK_WIDGET (gtk_builder_get_object (builder, "window"));
  widgets->btn_download = GTK_WIDGET(gtk_builder_get_object(builder, "btn_download"));
  widgets->entry_main = GTK_WIDGET(gtk_builder_get_object(builder, "entry_main"));

  gtk_builder_connect_signals(builder, widgets);

  g_object_unref(builder);

  gtk_widget_show(widgets->window);

  gtk_main();

  g_slice_free (widgets_t, widgets);

  return 0;
}

void on_window_destroy(void){
  gtk_main_quit();
}

void on_btn_download_clicked (GtkButton *btn_download, void *data){
    widgets_t *widgets = (widgets_t *)data;
    const gchar *name = gtk_entry_get_text(GTK_ENTRY (widgets->entry_main));

    printf("%s\n", name);
}
