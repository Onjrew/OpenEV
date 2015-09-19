/***************************************************************************/
/***************************************************************************/
/*
    CRS.H - Center for Remote Sensing rectification routines

    Written By: Brian J. Buckley

            At: The Center for Remote Sensing
                Michigan State University
                302 Berkey Hall
                East Lansing, MI  48824
                (517)353-7195

    Written: 12/19/91

    Last Update: 12/26/91 Brian J. Buckley
*/
/***************************************************************************/
/***************************************************************************/

#define MAXORDER 3

#define G_calloc calloc
#define G_free free

struct Control_Points
{
    int  count;
    double *e1;
    double *n1;
    double *e2;
    double *n2;
    int *status;
};

/* crs.c */
int CRS_georef(double, double, double *, double *, double [], double [], int);
int CRS_compute_georef_equations(struct Control_Points *,
    double [], double [], double [], double [], int);

