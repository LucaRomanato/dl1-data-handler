/** 
 * @file imageExtractor_v2.h
 * @brief Header file for imageExtractor_v2.
 * */ 

#ifndef __IMAGEEXTRACTOR_H__  
#define __IMAGEEXTRACTOR_H__  

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cmath> 
#include <algorithm> 
#include <iomanip>
#include <cassert>

#include <sys/stat.h>
#include <unistd.h>

#include <TH2F.h>
#include <TFile.h>
#include <TChain.h>
#include <TTree.h>
#include <TBranch.h>
#include <TCanvas.h>
#include <TPaveText.h>
#include <TStyle.h>
#include <TMath.h>
#include <TError.h>
#include <TSystem.h>
#include <TUnixSystem.h>

#include <opencv2/highgui.hpp>
#include <exiv2.hpp>
#include <xmp.hpp>
#include <image.hpp>
#include <properties.hpp>

//#include <hdf5.h>
#include "H5Cpp.h"

const int RANK = 4;
const int IMAGE_CHANNELS = 3;
const int IMAGE_WIDTH = 240;
const int IMAGE_LENGTH = 240;

/**
 * @fn int processCAREdata(TFile *file, TPaveText *pt, TH2F *hcamera, TCanvas *ccamera, std::vector<double> v_xcoord, std::vector<double> v_ycoord, int num_channels, std::string output_dir)
 *
 * @brief Reads data file in CARE format and generates image in output directory.
 *
 * @param file Tfile object from ROOT data file
 * @param pt A text box containing information on event
 * @param hcamera Histogram containing the summed charge in each channel
 * @param ccamera TCanvas containing image
 * @param v_xcoord vector of x coordinates for telescope channels
 * @param v_ycoord vector of y coordinates for telescope channels
 * @param num_channels number of channels in telescope data (from config file)
 * @param output_dir directory for generated .png and eps images
 *
 * @return returns 0 on success, 1 on failure
 */

//int processCAREdata(TFile *file, TPaveText *pt, TH2F *hcamera, TCanvas *ccamera, std::vector<double> v_xcoord, std::vector<double> v_ycoord, int num_channels, std::string output_dir);

/**
 * @fn int processEDdata(TFile *file, TPaveText *pt, TH2F *hcamera, TCanvas *ccamera, std::vector<double> v_xcoord, std::vector<double> v_ycoord, int num_channels, std::string output_dir)
 *
 * @brief Reads data file in Event Display format and generates image in output directory.
 *
 * @param file Tfile object from ROOT data file
 * @param pt A text box containing information on event
 * @param hcamera Histogram containing the summed charge in each channel
 * @param ccamera TCanvas containing image
 * @param v_xcoord vector of x coordinates for telescope channels
 * @param v_ycoord vector of y coordinates for telescope channels
 * @param num_channels number of channels in telescope data (from config file)
 * @param output_dir directory for generated .png and eps images
 *
 * @return returns 0 on success, 1 on failure
 */

int processEDdata(TChain *data_chain, TChain *tel_chain, TChain *mscw_chain,TPaveText *pt, TH2F *hcamera, TCanvas *ccamera, std::vector<double> v_xcoord, std::vector<double> v_ycoord, int num_channels, std::string output_filename, std::string output_dir);

/**
 * @fn int getFirstBin(unsigned short int ***trace, int tel, int channel, int num_samples,int ped_rm)
 *
 * @brief Gets starting sample for trace integration by calculating first half-max
 * sample and checking boundary conditions.
 *
 * @param trace 3D matrix containing charge values per sample per channel
 * per telescope
 * @param tel number of current telescope
 * @param channel number of current channel
 * @param num_samples total number of samples per channel
 * @param ped_rm pedestal subtraction from charge counts
 *
 * @return returns number of starting sample for trace integration
 */
int getFirstBin(unsigned short int ***trace, int tel, int channel, int num_samples,int ped_rm);

/**
 * @fn void readConfig(std::string filepath, std::vector<int>& channels, std::vector<double>& x_coord, std::vector<double>& y_coord)
 *
 * @brief Reads telescope configuration file and saves channel-position mappings
 * into three vectors.
 *
 * @param filepath Filepath for telescope config file
 * @param channels vector to be filled with telescope channel numbers
 * @param x_coord vector to be filled with channel x coordinates
 * @param y_coord vector to be filled with channel y coordinates
 *
 */
void readConfig(std::string filepath, std::vector<int>& channels, std::vector<double>& x_coord, std::vector<double>& y_coord);

/**
 * @fn int createImage(TH2F *hcam, std::string img_name,struct metadata md)
 *
 * @brief Takes TH2F histogram and metadata container and generates event image.
 *
 * @param hcam 2D histogram containing the summed charge in each telescope
 * channel
 * @param img_name name for generated image
 * @param md container of metadata values to be added to generated image
 * using Exiv2
 *
 * @return returns 0 on success, 1 on failure
 */

int createImageTensor(TH2F *hcam, UInt_t (&img_arr)[1][IMAGE_CHANNELS][IMAGE_WIDTH][IMAGE_LENGTH]);

#endif 
