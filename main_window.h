#pragma once

/// \file main_window.h
/// \brief Hauptfenster mit Menueleiste und Tastatur-Ereignissen.
#include <api/api.h>
#include <gdk/gdkkeysyms.h>
#include <stdbool.h>
#include <stdint.h>

#include "application.h" // IWYU pragma: keep.

/// \brief Zustand eines Hauptfensters samt Menue und Tastatur-Controller.
typedef struct gui_main_window
{
	GtkApplication* app;   ///< zugehoerige Anwendung.
	GtkEventController* keyboard_controller;   ///< Controller fuer Tasten-Ereignisse.
	GtkWidget* main_window;   ///< das Fenster-Widget.
	GMenu* menu_bar;   ///< Wurzel der Menueleiste.
	GMenu* file_menu;   ///< Standard-Untermenue "File".
	void* user_data;   ///< frei verwendbarer Zeiger des Aufrufers.
} *gui_main_window_t;

/// \brief Erzeugt ein Hauptfenster und praesentiert es.
/// \param app Anwendung, zu der das Fenster gehoert.
/// \param width_pix Breite in Pixeln.
/// \param height_pix Hoehe in Pixeln.
/// \param user_data frei verwendbarer Zeiger des Aufrufers.
/// \param show_menu true, wenn die Menueleiste sichtbar sein soll.
/// \param resizeable true, wenn das Fenster groessenveraenderbar ist.
/// \return das neue Fenster-Widget.
/// \note Ruft den gui_main_window-Callback mit GE_BEFORE_PRESENT zwischen Aufbau und
///       Darstellung sowie mit GE_AFTER_PRESENT danach auf.
GtkWidget* gui_main_window_create(GtkApplication* app, uint32_t width_pix, uint32_t height_pix, user_data_stack_t user_data,
	bool show_menu, bool resizeable);
/// \brief Legt ein Untermenue an und haengt es an die Menueleiste.
/// \param menu_bar Wurzel der Menueleiste.
/// \param sub_menu_name Anzeigename des Untermenues.
/// \return das neue Untermenue.
GMenu* gui_main_window_create_sub_menu(GMenu* menu_bar, const char* sub_menu_name);
/// \brief Fuegt dem Untermenue einen Eintrag hinzu und registriert die zugehoerige Aktion.
/// \param sub_menu Ziel-Untermenue.
/// \param item_name Anzeigename des Eintrags.
/// \param action_name Aktionsname ohne Praefix (wird als "app.<action_name>" registriert).
/// \param core Hauptfenster-Zustand, an den die Aktion gebunden wird.
void gui_main_window_add_sub_menu_item(GMenu* sub_menu, const char* item_name, const char* action_name, gui_main_window_t core);
