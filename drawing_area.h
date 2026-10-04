#pragma once

/// \file drawing_area.h
/// \brief Zeichenflaeche fuer eigene Cairo-Darstellung und Mausklicks.
#include <gtk/gtk.h>

/// \brief Zustand einer Zeichenflaeche.
typedef struct gui_drawing_area
{
	GtkWidget* drawing_area;   ///< das Zeichenflaechen-Widget.
	void* user_data;   ///< frei verwendbarer Zeiger des Aufrufers.
	uint32_t id;   ///< vom Aufrufer vergebene Kennung.
} *gui_drawing_area_t;

/// \brief Erzeugt eine Zeichenflaeche fester Groesse mit Draw- und Klick-Handler.
/// \param id vom Aufrufer vergebene Kennung.
/// \param width angeforderte Breite in Pixeln.
/// \param height angeforderte Hoehe in Pixeln.
/// \param user_data frei verwendbarer Zeiger des Aufrufers.
/// \return das neue Zeichenflaechen-Widget.
/// \note Der gui_drawing_area-Callback wird mit GE_DA_DRAW bzw. GE_DA_MOUSE_CLICK_LEFT aufgerufen.
GtkWidget* gui_drawing_area_create(uint32_t id, uint32_t width, uint32_t height, void* user_data);
