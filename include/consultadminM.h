#ifndef CONSULTADMINM_H
#define CONSULTADMINM_H

int argc;
char **argv;
char *email;
void onDestroyConM(GtkWidget *pwindow ,gpointer data);
void ConsultAdminM(int argc,char **argv);
static gboolean onClickConM( GtkWidget *widget,GdkEventButton *event,gpointer data );

#endif // CONSULTADMINM_H
