#ifndef BIN_H
#define BIN_H

#include <Container.h>

namespace Gtk
{
    class Bin : public Container
    {
    public:
        Bin() { }
        virtual ~Bin(void)
            { gtk_widget_destroy(GTK_WIDGET(gwidget)); g_free(gwidget);}
    public:
        GtkWidget* GetChild(void)
            { return gtk_bin_get_child(GTK_BIN(gwidget)); }
    };
}

#endif // BIN_H
