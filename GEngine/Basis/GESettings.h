#ifndef GESETTINGS_H
#define GESETTINGS_H


//Gjk and Epa
#define gjk_margin 0.05f


//contacts
#define max_manifold_points_number 4

struct GEVersion {
    int major;
    int minor;
    int revision;
};

extern GEVersion ge_version;

#endif