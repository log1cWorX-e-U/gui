#pragma once

/// \file switch.h
/// \brief Umschalter (an/aus).
#include <gtk/gtk.h>
#include <stdint.h>
#include <stdbool.h>

/// \brief Zustand eines Umschalters.
typedef struct _gui_switch
{
    GtkWidget* switch_widget;   ///< das Umschalter-Widget.
    uint32_t id;   ///< vom Aufrufer vergebene Kennung.
    void* user_data;   ///< frei verwendbarer Zeiger des Aufrufers.
} *gui_switch_t;

/// \brief Erzeugt einen Umschalter.
/// \param id vom Aufrufer vergebene Kennung.
/// \param active Anfangszustand.
/// \param user_data frei verwendbarer Zeiger des Aufrufers.
/// \return das neue Umschalter-Widget.
GtkWidget* gui_switch_create(uint32_t id, bool active, void* user_data);
/// \brief Aktueller Zustand eines Umschalters.
/// \param switch_widget der Umschalter.
/// \return true, wenn eingeschaltet.
bool gui_switch_get_active(GtkWidget* switch_widget);
/// \brief Setzt den Zustand eines Umschalters.
/// \param switch_widget der Umschalter.
/// \param active neuer Zustand.
void gui_switch_set_active(GtkWidget* switch_widget, bool active);
