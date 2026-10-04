#pragma once

/// \file application.h
/// \brief Einstiegspunkt: startet die GTK-Anwendung und ihre Hauptschleife.
#include <gtk/gtk.h>

/// \brief Laufende GTK-Anwendung samt frei verwendbaren Nutzerdaten.
typedef struct gui_application
{
	GtkApplication* app;   ///< zugrundeliegende GTK-Anwendung.
	void* user_data;   ///< frei verwendbarer Zeiger des Aufrufers.
} *gui_application_t;

/// \brief Erzeugt die GTK-Anwendung und fuehrt die Hauptschleife aus.
/// \param name Anwendungs-ID (z. B. "org.example.app").
/// \param argc Anzahl der Argumente aus main().
/// \param argv Argumentvektor aus main().
/// \param user_data frei verwendbarer Zeiger; spaeter via gui_application_t erreichbar.
/// \return GTK-Statuscode (0 bei normalem Ende).
int32_t gui_application_run(const char* name, int argc, char **argv, void* user_data);
