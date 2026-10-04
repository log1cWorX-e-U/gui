#pragma once

/// \file box.h
/// \brief Container fuer die vertikale und horizontale Anordnung von Widgets.
#include "widget.h"

/// \brief Erzeugt eine vertikale Box.
/// \param spacing Abstand zwischen den Kindern in Pixeln.
/// \return das neue Box-Widget.
GtkWidget* gui_box_vertical_create(uint32_t spacing);
/// \brief Erzeugt eine horizontale Box.
/// \param spacing Abstand zwischen den Kindern in Pixeln.
/// \return das neue Box-Widget.
GtkWidget* gui_box_horizontal_create(uint32_t spacing);
/// \brief Haengt ein einzelnes Widget am Ende an die Box an.
/// \param box Ziel-Box.
/// \param widget anzuhangendes Widget.
void gui_box_append_widget(GtkWidget* box, GtkWidget* widget);
/// \brief Haengt mehrere Widgets am Ende an die Box an.
/// \param box Ziel-Box.
/// \param widgets Array der anzuhangenden Widgets.
/// \param count Anzahl der Widgets in widgets.
void gui_box_append_widgets(GtkWidget* box, widget_array_t widgets, uint32_t count);
