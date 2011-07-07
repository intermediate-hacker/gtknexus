#ifndef OBJECT_H
#define OBJECT_H

#include <gtk/gtk.h>

namespace Gtk
{
    class Object
    {
    public:
        Object() {}
        virtual ~Object()
            { gtk_object_destroy(GTK_OBJECT(object)); g_free(object); }
    public:
        void Sink(void) { gtk_object_sink(GTK_OBJECT(object)); }
// Ref Functions
    public:
        GtkObject* Ref(void) {return gtk_object_ref(GTK_OBJECT(object)); }
        void UnRef(void) { gtk_object_unref(GTK_OBJECT(object)); }
        void WeakRef(GDestroyNotify notify, gpointer data)
            { gtk_object_weakref(GTK_OBJECT(object),notify,data); }
        void WeakUnRef(GDestroyNotify notify, gpointer data)
            { gtk_object_weakunref(GTK_OBJECT(object),notify,data); }

    public:
        void Destroy(void) { gtk_object_destroy(GTK_OBJECT(object)); }
    public:
        GtkObject *object;

    };
}

#endif // OBJECT_H
