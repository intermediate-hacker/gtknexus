#ifndef WIDGET_H
#define WIDGET_H

#include <Object.h>

namespace Gtk
{
    class Widget : public Object
    {
    public:
//Constructors / Destructors
        Widget(GtkWidget *widget) :gwidget(widget) { }
        Widget(void) { }
        virtual ~Widget()
            { gtk_widget_destroy(GTK_WIDGET(gwidget)); g_free(gwidget); }
//Ref Functions
    public:
        GtkWidget* Ref(void) { return gtk_widget_ref(GTK_WIDGET(gwidget)); }
        void UnRef(void) { gtk_widget_unref(GTK_WIDGET(gwidget)); }

//Destroy Functions
        void Destroy(void) { gtk_widget_destroy(GTK_WIDGET(gwidget)); }
        void Destroyed(GtkWidget** w_pointer)
            { gtk_widget_destroyed(GTK_WIDGET(gwidget),w_pointer); }

//Important Functions :D
        void UnParent(void) { gtk_widget_unparent(GTK_WIDGET(gwidget)); }

//Show / Hide
        void Show(void) { gtk_widget_show(GTK_WIDGET(gwidget)); }
        void ShowNow(void) { gtk_widget_show_now(GTK_WIDGET(gwidget)); }
        void Hide(void) { gtk_widget_hide(GTK_WIDGET(gwidget)); }
        void ShowAll(void) { gtk_widget_show_all(GTK_WIDGET(gwidget)); }
        void HideAll(void) { gtk_widget_hide_all(GTK_WIDGET(gwidget)); }

// Map / UnMap
        void Map(void) { gtk_widget_map(GTK_WIDGET(gwidget)); }
        void UnMap(void) { gtk_widget_unmap(GTK_WIDGET(gwidget)); }

//Realize / UnRealize
        void Realize(void) { gtk_widget_realize(GTK_WIDGET(gwidget)); }
        void UnRealize(void) { gtk_widget_unrealize(GTK_WIDGET(gwidget)); }

//Queue
        void QueueDraw(void) { gtk_widget_queue_draw(GTK_WIDGET(gwidget)); }
        void QueueResize(void) { gtk_widget_queue_resize(GTK_WIDGET(gwidget)); }
        void QueueResizeNoRedraw(void)
            {gtk_widget_queue_resize_no_redraw(GTK_WIDGET(gwidget));}
//Draw
        void Draw(const GdkRectangle *area)
            { gtk_widget_draw(GTK_WIDGET(gwidget), area); }


    public:
        GtkWidget* gwidget;
    };
}
#endif // WIDGET_H
