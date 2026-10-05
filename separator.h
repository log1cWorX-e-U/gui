#pragma once

/// \file separator.h
/// \brief Trennlinie zwischen Widgets.
#include <api/api.h>
#include <gtk/gtk.h>
#include <stdint.h>

/// \brief Zustand einer Trennlinie.
typedef struct _gui_separator
{
    GtkWidget* separator;   ///< das Trennlinien-Widget.
    uint32_t id;   ///< vom Aufrufer vergebene Kennung.
    user_data_t user_data;   ///< frei verwendbarer Zeiger des Aufrufers.
} *gui_separator_t;

/// \brief Erzeugt eine waagerechte oder senkrechte Trennlinie.
/// \param id vom Aufrufer vergebene Kennung.
/// \param horizontal true fuer eine waagerechte Linie, sonst senkrecht.
/// \param user_data frei verwendbarer Zeiger des Aufrufers.
/// \return das neue Trennlinien-Widget.
GtkWidget* gui_separator_create(uint32_t id, bool horizontal, void* user_data);
