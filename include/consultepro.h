#ifndef CONSULTEPRO_H
#define CONSULTEPRO_H

int argc;
char **argv;
char *email;
void onDestroyConP(GtkWidget *pwindow ,gpointer data);
void ConsulteProduit(int argc,char **argv);
static gboolean onClickConP( GtkWidget *widget,GdkEventButton *event,gpointer data );
#endif // CONSULTEPRO_H
