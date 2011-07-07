#ifndef CONTAINER_H
#define CONTAINER_H

#include <Widget.h>

namespace Gtk
{
    class Container : public Widget
    {
    public:
        Container() { }
        virtual ~Container()
            { gtk_widget_destroy(GTK_WIDGET(gwidget)); g_free(gwidget); }
    public:
        void Add(GtkWidget* widget)
            { gtk_container_add(GTK_CONTAINER(gwidget),widget); }
        void Remove(GtkWidget* widget)
            { gtk_container_remove(GTK_CONTAINER(gwidget),widget); }
    public:
        void SetBorderWidth(guint width)
            { gtk_container_set_border_width(GTK_CONTAINER(gwidget),width); }
        guint GetBorderWidth(void)
            { return gtk_container_get_border_width(GTK_CONTAINER(gwidget)); }

    };
}

#endif // CONTAINER_H
