#pragma once

/// \file label.h
/// \brief Nicht editierbares Text-Widget.
#include <gtk/gtk.h>
#include <stdint.h>

/// \brief Zustand eines Labels.
typedef struct _gui_label
{
    GtkWidget* label;   ///< das Label-Widget.
    uint32_t id;   ///< vom Aufrufer vergebene Kennung.
    void* user_data;   ///< frei verwendbarer Zeiger des Aufrufers.
} *gui_label_t;

/// \brief Erzeugt ein Label mit Text.
/// \param id vom Aufrufer vergebene Kennung.
/// \param text Anzeigetext.
/// \param user_data frei verwendbarer Zeiger des Aufrufers.
/// \return das neue Label-Widget.
GtkWidget* gui_label_create(uint32_t id, const char* text, void* user_data);
/// \brief Anzeigetext eines Labels.
/// \param label das Label.
/// \return der Text des Labels (nicht kopiert).
const char* gui_label_get_text(GtkWidget* label);
/// \brief Setzt den Anzeigetext eines Labels.
/// \param label das Label.
/// \param text neuer Text.
void gui_label_set_text(GtkWidget* label, const char* text);
