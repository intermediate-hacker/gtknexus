#ifndef WINDOW_H
#define WINDOW_H

#include <Bin.h>

namespace Gtk
{
    class Window : public Bin
    {
    public:
        Window(GtkWindowType type = GTK_WINDOW_TOPLEVEL)
            { gwidget = gtk_window_new(type); };
        virtual ~Window()
            { gtk_widget_destroy(GTK_WIDGET(gwidget)); g_free(gwidget); }
    public:
        void SetTitle(const gchar* title)
            { gtk_window_set_title(GTK_WINDOW(gwidget),title); }
    public:
        void SetResizable(gboolean resizable)
            { gtk_window_set_resizable(GTK_WINDOW(gwidget),resizable); }
        gboolean GetResizable(void)
            { return gtk_window_get_resizable(GTK_WINDOW(gwidget)); }
    public:
        void SetFocus(GtkWidget* focus)
            { gtk_window_set_focus(GTK_WINDOW(gwidget), focus); }
        GtkWidget* GetFocus(void)
            { return gtk_window_get_focus(GTK_WINDOW(gwidget)); }
    };
}

#endif // WINDOW_H
