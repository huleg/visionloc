#include "visionloc_multi.hh"
#include <unistd.h>
#include <iostream>

int main()
{
    std::vector<Marker> markers;
    int tag;

    start_visionloc();

    int i;
    for(i = 0; i < 10; i++)
    {
        markers = get_markers_from_camera(0);
        tag = get_tag(0);
        std::cout << "Num of markers recognized " << markers.size();
        for (std::vector<Marker>::iterator itm = markers.begin(); 
                itm != markers.end(); ++itm){
            std::cout << " with id " << itm->id << " and tag " <<
                tag << std::endl;
        }

        sleep(1);
    }

    stop_visionloc();
}