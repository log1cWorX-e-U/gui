#pragma once

/// \file button.h
/// \brief Druck-, Umschalt-, Auswahl- und Drehknopf-Widgets.
#include <api/api.h>
#include <gtk/gtk.h>
#include <stdint.h>
#include <stdbool.h>

/// \brief Zustand eines Buttons.
typedef struct _gui_button
{
    GtkWidget* button;   ///< das Button-Widget.
    uint32_t id;   ///< vom Aufrufer vergebene Kennung.
    user_data_t user_data;   ///< frei verwendbarer Zeiger des Aufrufers.
} *gui_button_t;

/// \brief Konfiguration fuer gui_button_create.
typedef struct gui_button_configuration
{
    const char* label;   ///< Beschriftung; NULL laesst das Label weg.
    bool toggle;   ///< true fuer einen Umschalt-Button.
    const char* tooltip;   ///< Tooltip-Text; NULL laesst ihn weg.
} *gui_button_configuration_t;

/// \brief Konfiguration fuer gui_button_spin_create.
typedef struct gui_spin_button_configuration
{
    float alignment;   ///< Textausrichtung im Feld (0.0 bis 1.0).
    double value;   ///< Anfangswert.
    double min;   ///< Kleinstwert.
    double max;   ///< Groesstwert.
    double increment;   ///< Schrittweite.
    uint32_t digits;   ///< Anzahl der Nachkommastellen.
    const char* tooltip;   ///< Tooltip-Text; NULL laesst ihn weg.
} *gui_spin_button_configuration_t;

/// \brief Erzeugt einen einfachen oder umschaltbaren Button.
/// \param id vom Aufrufer vergebene Kennung.
/// \param configuration Beschriftung, Umschalt-Flag und Tooltip.
/// \param user_data frei verwendbarer Zeiger des Aufrufers.
/// \return das neue Button-Widget.
/// \note Der gui_button-Callback wird mit GE_B_CLICKED bzw. GE_B_TOGGLED aufgerufen.
GtkWidget* gui_button_create(uint32_t id, gui_button_configuration_t configuration, user_data_stack_t user_data);
/// \brief Erzeugt einen Auswahlknopf aus einer Textliste.
/// \param id vom Aufrufer vergebene Kennung.
/// \param strings NULL-terminierte Liste der Auswahltexte.
/// \param user_data frei verwendbarer Zeiger des Aufrufers.
/// \return das neue Auswahl-Widget.
GtkWidget* gui_button_drop_down_create(uint32_t id, const char* strings[], user_data_stack_t user_data);
/// \brief Index der aktuellen Auswahl.
/// \param drop_down_button der Auswahlknopf.
/// \return Index des gewaehlten Eintrags.
int32_t gui_button_drop_down_get_selection(GtkWidget* drop_down_button);
/// \brief Erzeugt einen Drehknopf zur Zahleneingabe.
/// \param id vom Aufrufer vergebene Kennung.
/// \param configuration Wertebereich, Schrittweite und Nachkommastellen.
/// \param user_data frei verwendbarer Zeiger des Aufrufers.
/// \return das neue Drehknopf-Widget.
/// \note Der gui_button-Callback wird bei Wertänderung mit GE_B_SELECTED aufgerufen.
GtkWidget* gui_button_spin_create(uint32_t id, gui_spin_button_configuration_t configuration, user_data_stack_t user_data);
/// \brief Uebernimmt eine neue Konfiguration fuer einen Drehknopf.
/// \param spin_button der Drehknopf.
/// \param configuration neue Wertebereichs- und Schrittweitenwerte.
void gui_button_spin_set_configuration(GtkWidget* spin_button, gui_spin_button_configuration_t configuration);
/// \brief Aktueller Zahlenwert eines Drehknopfs.
/// \param spin_button der Drehknopf.
/// \return der aktuelle Wert.
double gui_button_spin_get_double(GtkWidget* spin_button);
/// \brief Setzt den Zahlenwert eines Drehknopfs.
/// \param spin_button der Drehknopf.
/// \param value neuer Wert.
void gui_button_spin_set_double(GtkWidget* spin_button, double value);
/// \brief Aktueller Zustand eines Umschalt-Buttons.
/// \param button_toggle der Umschalt-Button.
/// \return true, wenn eingeschaltet.
bool gui_button_toggle_is_active(GtkWidget* button_toggle);
