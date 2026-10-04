#pragma once

/// \file events.h
/// \brief Ereignistypen und Ereignisdaten der gui-Rueckrufe.
#include <gtk/gtk.h>

/// \brief Art eines gui-Ereignisses.
typedef enum
{
	GE_A_STARTUP,            ///< Anwendung gestartet.
	GE_A_ACTIVATE,           ///< Anwendung aktiviert.
	GE_A_SHUTDOWN,           ///< Anwendung wird beendet.
	GE_BEFORE_PRESENT,       ///< Hauptfenster vor der Darstellung.
	GE_AFTER_PRESENT,        ///< Hauptfenster nach der Darstellung.
	GE_CLOSE_REQUEST,        ///< Schliessen angefordert.
	GE_KEY_PRESSED,          ///< Taste gedrueckt.
	GE_KEY_RELEASED,         ///< Taste losgelassen.
	GE_DA_DRAW,              ///< Zeichenflaeche neu zu zeichnen.
	GE_DA_MOUSE_CLICK_LEFT,  ///< Linksklick auf der Zeichenflaeche.
	GE_B_CLICKED,            ///< Button gedrueckt.
	GE_B_TOGGLED,            ///< Umschalt-Button gewechselt.
	GE_B_SELECTED,           ///< Auswahl geaendert.
	GE_DIALOG_DESTROY,       ///< Dialog zerstoert.
	GE_DIALOG_CLOSE_REQUEST, ///< Dialog-Schliessen angefordert.
	GE_GL_RENDER,            ///< OpenGL-Flaeche neu zeichnen.
	GE_GL_REALIZE            ///< OpenGL-Kontext bereit.
} gui_event_type_t;

/// \brief Ereignisdaten vor der Darstellung des Hauptfensters (derzeit ohne Inhalt).
typedef struct _gui_before_present
{
	uint32_t dummy;   ///< Platzhalter.
} *gui_before_present_t;

/// \brief Ereignisdaten nach der Darstellung des Hauptfensters (derzeit ohne Inhalt).
typedef struct _gui_after_present
{
	uint32_t dummy;   ///< Platzhalter.
} *gui_after_present_t;

/// \brief Ereignisdaten einer Schliessen-Anforderung.
typedef struct _gui_close_request
{
	bool close;   ///< true, wenn geschlossen werden soll.
} *gui_close_request_t;

/// \brief Ereignisdaten einer gedrueckten Taste.
typedef struct _gui_key_pressed
{
	uint32_t keyval;   ///< Tastencode.
	bool handled;   ///< vom Rueckruf auf true setzen, wenn die Taste verbraucht wurde.
} *gui_key_pressed_t;

/// \brief Ereignisdaten einer losgelassenen Taste.
typedef struct _gui_key_released
{
	uint32_t keyval;   ///< Tastencode.
} *gui_key_released_t;

/// \brief Ereignisdaten eines Neuzeichnens der Zeichenflaeche.
typedef struct _gui_da_draw_event
{
	GtkDrawingArea* drawing_area;   ///< betroffene Zeichenflaeche.
	cairo_t* cr;   ///< Cairo-Kontext zum Zeichnen.
	uint32_t width;   ///< Breite der Flaeche.
	uint32_t height;   ///< Hoehe der Flaeche.
} *gui_da_draw_event_t;

/// \brief Ereignisdaten eines Linksklicks auf der Zeichenflaeche.
typedef struct _gui_da_mouse_left_click_event
{
	GtkDrawingArea* drawing_area;   ///< betroffene Zeichenflaeche.
	double x;   ///< x-Position des Klicks.
	double y;   ///< y-Position des Klicks.
	uint32_t n;   ///< Anzahl der Klicks.
} *gui_da_mouse_left_click_event_t;

/// \brief Ereignisdaten eines Button-Klicks.
typedef struct _gui_b_clicked_event
{
	GtkButton* button;   ///< betroffener Button.
} *gui_b_clicked_event_t;

/// \brief Ereignisdaten eines umgeschalteten Buttons.
typedef struct _gui_b_toggled_event
{
	GtkToggleButton* button;   ///< betroffener Umschalt-Button.
	bool active;   ///< neuer Zustand.
} *gui_b_toggled_event_t;

/// \brief Ereignisdaten beim Zerstoeren eines Dialogs.
typedef struct _gui_dialog_destroy_event
{
	GtkWidget* dialog;   ///< der betroffene Dialog.
} *gui_dialog_destroy_event_t;

/// \brief Ereignisdaten einer Dialog-Schliessen-Anforderung.
typedef struct _gui_dialog_close_request_event
{
	GtkWidget* dialog;   ///< der betroffene Dialog.
	bool close;   ///< true, wenn geschlossen werden soll.
} *gui_dialog_close_request_event_t;

/// \brief Vereinigung aller moeglichen Ereignisdaten.
/// \note Welches Mitglied gueltig ist, bestimmt gui_event::type.
typedef union _gui_event_data
{
	struct _gui_before_present before_present;   ///< Daten vor der Darstellung.
	struct _gui_after_present after_present;   ///< Daten nach der Darstellung.
	struct _gui_close_request close_request;   ///< Schliessen-Anforderung.
	struct _gui_key_pressed key_pressed;   ///< gedrueckte Taste.
	struct _gui_key_released key_released;   ///< losgelassene Taste.
	struct _gui_da_draw_event da_draw;   ///< Neuzeichnen.
	struct _gui_da_mouse_left_click_event da_mouse_left_click;   ///< Mausklick.
	struct _gui_b_clicked_event b_clicked;   ///< Button-Klick.
	struct _gui_b_toggled_event b_toggled;   ///< Umschalten.
	struct _gui_dialog_destroy_event dialog_destroy;   ///< Dialog zerstoert.
	struct _gui_dialog_close_request_event dialog_close_request;   ///< Dialog-Schliessen.
} *gui_event_data_t;

/// \brief Ein vollstaendiges gui-Ereignis aus Typ und zugehoerigen Daten.
typedef struct gui_event
{
	gui_event_type_t type;   ///< Art des Ereignisses.
	union _gui_event_data data;   ///< zugehoerige Daten.
} *gui_event_t;
