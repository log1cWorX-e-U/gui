#pragma once

/// \file dialog.h
/// \brief Eigenstaendiges Fenster fuer Dialoge.
#include <api/api.h>
#include <gtk/gtk.h>
#include <stdint.h>
#include <stdbool.h>

/// \brief Zustand eines Dialog-Fensters.
typedef struct _gui_dialog
{
    GtkWidget* dialog;   ///< das Dialog-Fenster-Widget.
    uint32_t id;   ///< vom Aufrufer vergebene Kennung.
    user_data_t user_data;   ///< frei verwendbarer Zeiger des Aufrufers.
} *gui_dialog_t;

/// \brief Erzeugt ein anfangs modales Dialog-Fenster.
/// \param id vom Aufrufer vergebene Kennung.
/// \param title Fenstertitel.
/// \param width Breite in Pixeln.
/// \param height Hoehe in Pixeln.
/// \param user_data frei verwendbarer Zeiger des Aufrufers.
/// \return das neue Fenster-Widget.
/// \note Der gui_dialog-Callback wird mit GE_DIALOG_DESTROY bzw. GE_CLOSE_REQUEST aufgerufen.
GtkWidget* gui_dialog_create(uint32_t id, const char* title, uint32_t width, uint32_t height, user_data_stack_t user_data);
/// \brief Setzt den Fenstertitel.
/// \param dialog der Dialog.
/// \param title neuer Titel.
void gui_dialog_set_title(GtkWidget* dialog, const char* title);
/// \brief Fordert das Schliessen des Dialogs an.
/// \param dialog der Dialog.
void gui_dialog_close(GtkWidget* dialog);
/// \brief Setzt die Modalitaet des Dialogs.
/// \param dialog der Dialog.
/// \param modal true, wenn der Dialog modal sein soll.
void gui_dialog_set_modal(GtkWidget* dialog, bool modal);
/// \brief Bindet den Dialog an ein Elternfenster.
/// \param dialog der Dialog.
/// \param parent das Elternfenster.
void gui_dialog_set_transient_for(GtkWidget* dialog, GtkWidget* parent);
/// \brief Setzt das Kind-Widget des Dialogs.
/// \param dialog der Dialog.
/// \param child einzubettendes Widget.
void gui_dialog_set_child(GtkWidget* dialog, GtkWidget* child);
/// \brief Praesentiert den Dialog.
/// \param dialog der Dialog.
void gui_dialog_present(GtkWidget* dialog);
/// \brief Legt fest, ob der Dialog groessenveraenderbar ist.
/// \param dialog der Dialog.
/// \param resizable true zum Erlauben der Groessenaenderung.
void gui_dialog_set_resizable(GtkWidget* dialog, bool resizable);
/// \brief Setzt die Standardgroesse des Dialogs.
/// \param dialog der Dialog.
/// \param width Breite in Pixeln.
/// \param height Hoehe in Pixeln.
void gui_dialog_set_default_size(GtkWidget* dialog, uint32_t width, uint32_t height);
