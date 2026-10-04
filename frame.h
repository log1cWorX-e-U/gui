#pragma once

/// \file frame.h
/// \brief Rahmen mit beschriftetem Rand um ein Kind-Widget.
#include <gtk/gtk.h>

/// \brief Erzeugt einen Rahmen mit Beschriftung um widget.
/// \param label Beschriftung des Rahmens (darf NULL sein).
/// \param widget einzubettendes Kind-Widget.
/// \return das neue Rahmen-Widget.
GtkWidget* gui_frame_create(const char* label, GtkWidget* widget);
/// \brief Kind-Widget eines Rahmens.
/// \param frame der Rahmen.
/// \return das Kind-Widget oder NULL.
GtkWidget* gui_frame_get_child(GtkFrame* frame);
