#pragma once

/// \file notebook.h
/// \brief Reiter-Container mit mehreren Seiten.
#include <gtk/gtk.h>

/// \brief Legt ein Notebook als Kind von parent an.
/// \param parent Fenster, das das Notebook aufnimmt.
/// \note Das Notebook wird als alleiniges Kind gesetzt und von den uebrigen
///       Notebook-Funktionen aus parent wieder ermittelt.
void notebook_create(GtkWidget* parent);
/// \brief Haengt eine neue Seite mit Beschriftung an.
/// \param notebook_parent Fenster mit dem Notebook.
/// \param widget Inhalt der Seite.
/// \param label Beschriftung des Reiters.
/// \return Index der neuen Seite.
uint32_t notebook_append_page(GtkWidget* notebook_parent, GtkWidget* widget, const char* label);
/// \brief Seite an einem Index.
/// \param notebook_parent Fenster mit dem Notebook.
/// \param index Index der Seite.
/// \return das Widget der Seite.
GtkWidget* notebook_get_page(GtkWidget* notebook_parent, uint32_t index);
