#pragma once

/// \file widget.h
/// \brief Allgemeine Hilfsfunktionen fuer beliebige GTK-Widgets.
#include <gtk/gtk.h>
#include <stdbool.h>

/// \brief Einfaches Feld von Widget-Zeigern.
typedef GtkWidget* widget_array_t[];

/// \brief Setzt den CSS-Namen eines Widgets.
/// \param widget das Widget.
/// \param label der neue Name.
void gui_widget_set_name(GtkWidget* widget, const char* label);
/// \brief CSS-Name eines Widgets.
/// \param widget das Widget.
/// \return der gesetzte Name.
const char* gui_widget_get_name(GtkWidget* widget);

/// \brief Setzt die vier Aussenabstaende eines Widgets.
/// \param widget das Widget.
/// \param start Abstand links (bzw. Startseite) in Pixeln.
/// \param end Abstand rechts (bzw. Endseite) in Pixeln.
/// \param top Abstand oben in Pixeln.
/// \param bottom Abstand unten in Pixeln.
void gui_widget_set_margins(GtkWidget* widget, int start, int end, int top, int bottom);
/// \brief Legt fest, ob das Widget horizontal mitwaechst.
/// \param widget das Widget.
/// \param expand true zum Mitwachsen.
void gui_widget_set_hexpand(GtkWidget* widget, bool expand);
/// \brief Setzt die horizontale Ausrichtung eines Widgets.
/// \param widget das Widget.
/// \param alignment gewuenschte Ausrichtung.
void gui_widget_set_halign(GtkWidget* widget, GtkAlign alignment);
