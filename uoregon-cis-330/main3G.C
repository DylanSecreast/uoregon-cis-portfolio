#include <PNMreader.h>
#include <PNMwriter.h>
#include <filters.h>

int main(int argc, char *argv[])
{



    PNMreader reader(argv[1]);

    Crop c;
    c.SetRegion(232, 1234, 47, 403);
    c.SetInput(reader.GetOutput());

    Shrinker s;
    s.SetInput(c.GetOutput());

    s.GetOutput()->Update();

    /*
    Crop crop;
    crop.SetRegion(300, 1400, 50, 400);
    crop.SetInput(reader.GetOutput());

    Transpose t;
    t.SetInput(crop.GetOutput());

    Invert i;
    i.SetInput(t.GetOutput());

    Color color(50, 1101, 0, 0, 128);

    LRConcat lr;
    lr.SetInput(color.GetOutput());
    lr.SetInput2(i.GetOutput());

    Color white(401, 1101, 255, 255, 255);

    Checkerboard cb;
    cb.SetInput(lr.GetOutput());
    cb.SetInput2(white.GetOutput());

    cb.GetOutput()->Update();
    */
    PNMwriter writer;
    writer.SetInput(s.GetOutput());
    writer.Write(argv[2]);

    CheckSum cs;
    cs.SetInput(s.GetOutput());
    cs.OutputCheckSum("proj3G_checksum");
}
