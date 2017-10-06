imageExtractor.C
Author: Daniel Nieto (nieto@nevis.columbia.edu)

Additional work by: Bryan Kim (bryan.sanghyuk.kim@gmail.com)

Description:

Read simulated CTA data in DST format and generates events' images in eps
and png formats. Uses exiv2 to mark event images with useful properties as
XMP metadata.

Dependencies:
- OpenCV 2.4.13
- ROOT 
- Exiv2 0.25

Compilation instructions:
- Run "make" to compile imageExtractor
- Run "make clean" to remove imageExtractor
- Run "make all" to recompile imageExtractor

Additional Scripts (see /scripts):
- normalizeImages.sh
  
- output.sh

- prepDataset.sh

- findDuplicates.sh

- generate_all.sh


To Do:

-Add cases to eventtype switch statement for other particle types
-Add script to update ROOT files with classification scores from Keras


