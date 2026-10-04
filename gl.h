#pragma once

/// \file gl.h
/// \brief OpenGL-Flaeche fuer selbst gerendertes Zeichnen.
#include <gtk/gtk.h>
#include <epoxy/gl.h>

/// \brief Zustand einer OpenGL-Flaeche.
typedef struct _gui_gl
{
	GtkWidget* gl_area;   ///< die OpenGL-Flaeche.
	gpointer user_data;   ///< frei verwendbarer Zeiger des Aufrufers.
	bool render_tick;   ///< true, sobald der Frame-Tick registriert ist.
} *gui_gl_t;

/// \brief Erzeugt eine OpenGL-Flaeche.
/// \param user_data frei verwendbarer Zeiger des Aufrufers.
/// \return das neue OpenGL-Widget.
/// \note Der gui_gl-Callback wird mit GE_GL_REALIZE (Kontext bereit) und
///       GE_GL_RENDER (jeder Frame) aufgerufen.
GtkWidget* gui_gl_create(gpointer user_data);
