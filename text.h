#pragma once

/// \file text.h
/// \brief Eingabefeld mit regelbasierter Zeichenfilterung.
#include <api/api.h>
#include <gtk/gtk.h>

/// \brief Regulaerer Ausdruck fuer nicht-negative ganze Zahlen.
#define REG_EXP_UNSIGNED_INTEGER    "[0]{0,1}|[1-9]{1}[0-9]{0,}"
/// \brief Regulaerer Ausdruck fuer ganze Zahlen mit optionalem Vorzeichen.
#define REG_EXP_SIGNED_INTEGER      "[0-]{0,1}|[-]{0,1}[1-9][0-9]{0,}"
/// \brief Regulaerer Ausdruck fuer Gleitkommazahlen mit Komma.
#define REG_EXP_FLOAT               "[0]{0,1}|[0][,]{0,1}|[0][,][0-9]{1,}|"\
                                    "[-]{0,1}|[-][0]{0,1}|[-][0][,]{0,1}|[-][0][,][0-9]{1,}|"\
                                    "[1-9]|[1-9][0-9]{1,}|[1-9][0-9]{1,}[,]{0,1}|[1-9][0-9]{1,}[,][0-9]{1,}|"\
                                    "[-][1-9]{1,}|[-][1-9][0-9]{1,}|[-][1-9][0-9]{1,}[,]{0,1}|[-][1-9][0-9]{1,}[,][0-9]{1,}|"\
                                    "[1-9][,]{0,1}|[1-9][,][0-9]{1,}|"\
                                    "[-][1-9][,]{0,1}|[-][1-9][,][0-9]{1,}"
/// \brief Regulaerer Ausdruck fuer Winkelgrade.
#define REG_EXP_DEG                 "[0]{0,1}|[0][,]{0,1}|[0][,][0-9]{1,4}|"\
                                    "[-]{0,1}|[-][0]{0,1}|[-][0][,]{0,1}|[-][0][,][0-9]{1,4}|"\
                                    "[1-9]{0,1}|[1-9][0-9]{0,1}|[1-9][0-9]{0,1}[,]{0,1}|[1-9][0-9]{0,1}[,][0-9]{1,4}|"\
                                    "[1-2]{0,1}|[1-2]{0,1}[0-9]{0,2}[,]{0,1}|[1-2]{1,2}[0-9]{0,2}[,][0-9]{1,4}|"\
                                    "[3]{0,1}|[3][5]{0,1}|[3][5][0-9]{0,1}|[3][5][0-9][,]{0,1}|[3][5][0-9][,][0-9]{1,4}|"\
                                    "[-][1-9]{0,1}|[-][1-9][0-9]{0,1}|[-][1-9][0-9]{0,1}[,]{0,1}|[-][1-9][0-9]{0,1}[,][0-9]{1,4}|"\
                                    "[-][1-2]{0,1}|[-][1-2][0-9]{0,2}|[-][1-2][0-9]{0,2}[,]{0,1}|[-][1-2][0-9]{0,2}[,][0-9]{1,4}|"\
                                    "[-][3]{0,1}|[-][3][0-5]{0,1}|[-][3][0-5][0-9]|[-][3][0-5][0-9][,]{0,1}|[-][3][0-5][0-9][,][0,9]{1,4}"
/// \brief Regulaerer Ausdruck fuer Winkelwerte im Bereich -90 bis 90 Grad.
#define REG_EXP_90_DEG              "[0]{0,1}|[0][,]{0,1}|[0][,][0-9]{1,4}|"\
                                    "[-]{0,1}|[-][0]{0,1}|[-][0][,]{0,1}|[-][0][,][0-9]{1,4}|"\
                                    "[1-9]{0,1}|[1-9][,]{0,1}|[1-9][,][0-9]{1,4}|"\
                                    "[1-8]{0,1}|[1-8][0-9]{0,1}|[1-8][0-9]{0,1}[,]{0,1}|[1-8][0-9]{0,1}[,][0-9]{1,4}|"\
                                    "[9]{0,1}|[9][0]{0,1}|[9][0][,]{0,1}|[9][0][,][0]{1,4}|"\
                                    "[-][1-9]{0,1}|[-][1-9][,]{0,1}|[-][1-9][,][0-9]{1,4}|"\
                                    "[-][1-8]{0,1}|[-][1-8][0-9]{0,1}|[-][1-8][0-9]{0,1}[,]{0,1}|[-][1-8][0-9]{0,1}[,][0-9]{1,4}|"\
                                    "[-][9]{0,1}|[-][9][0]{0,1}|[-][9][0][,]{0,1}|[-][9][0][,][0]{1,4}"


/// \brief Zustand eines Eingabefeldes samt Filterausdruck.
typedef struct _gui_text
{
    GtkWidget* text;   ///< das Eingabefeld-Widget.
    uint32_t id;   ///< vom Aufrufer vergebene Kennung.
    const char* regular_expression;   ///< Ausdruck zur Zeichenfilterung.
    user_data_t user_data;   ///< frei verwendbarer Zeiger des Aufrufers.
} *gui_text_t;

/// \brief Erzeugt ein Eingabefeld mit Zeichenfilter und Anfangswert.
/// \param id vom Aufrufer vergebene Kennung.
/// \param alignment Textausrichtung im Feld (0.0 links bis 1.0 rechts, wird begrenzt).
/// \param white_list regulaerer Ausdruck der erlaubten Eingaben.
/// \param value Anfangstext.
/// \param user_data frei verwendbarer Zeiger des Aufrufers.
/// \return das neue Eingabefeld-Widget.
GtkWidget* gui_text_create(uint32_t id, float alignment, const char* white_list, const char* value, user_data_stack_t user_data);
/// \brief Liest den Feldinhalt als Zahl.
/// \param text das Eingabefeld.
/// \return der Inhalt als double (atof).
double gui_text_get_double(GtkWidget* text);
