#include "fileread.hpp"

void fileReadList::performFileRead(const std::string filename) {
        
        // Access the string argument
        std::ifstream file(filename);

        // Check if the file is open
        if (!file.is_open()) {
            std::cerr << "Error opening the file!" << std::endl;
            throw std::runtime_error("Error opening the file: " + filename);
        }

        std::string keyword;
        std::string material;
        
        hittable_list objs;

        double minx, maxx, miny, maxy, zrec;
        double x, y, z;
        double x2, y2, z2;
        double r, g, b;
        double diaCoef;
        double metalCoef;
        double radius;

        std::string opera;
        double aspectNum;
        double aspectDen; 
        double aspect_ratio;      
        int image_width;
        int image_height;
        int samples_per_pixel;
        int max_depth;

        double fromx, fromy, fromz;
        double atx, aty, atz;
        double vupx, vupy, vupz;
        double vfov;
        double aperture;
        double dist_to_focus;
        double br, bg, bb;
        bool skylight;
        std::istringstream iss;

        std::string currentLine;
        std::getline(file, currentLine);
        currentLine.erase(std::remove_if(currentLine.begin(), currentLine.end(), ::isspace), currentLine.end());
        if(currentLine == "BSCENE"){
            while (currentLine != "ESCENE") {
                if(currentLine == "BADDOBJ"){
                    std::getline(file, currentLine);
                    currentLine.erase(std::remove_if(currentLine.begin(), currentLine.end(), ::isspace), currentLine.end());
                    
                    if(currentLine == "object_sphere"){

                        std::getline(file, currentLine);


                        iss.clear();
                        iss.str(currentLine);
                        iss >> keyword;
                        iss >> material;

                        if(material == "lambertian"){
                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> r >> g >> b;
                            auto matt = make_shared<lambertian>(color(r, g, b));

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> radius;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> x >> y >> z;

                            objs.add(make_shared<sphere>(point3(x, y, z), radius, matt));
                        }
                        
                        if(material == "dielectric"){
                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> diaCoef;
                                                
                            auto matt = make_shared<dielectric>(diaCoef);

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> radius;                            


                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> x >> y >> z;

                            objs.add(make_shared<sphere>(point3( x, y, z), radius, matt));
                        }

                        if(material == "metal"){
                            std::getline(file, currentLine);


                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> r >> g >> b;
                            
                            std::getline(file, currentLine);


                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> metalCoef;

                            auto matt = make_shared<metal>(color(r, g, b), metalCoef);

                            std::getline(file, currentLine);


                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> radius;                            



                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> x >> y >> z;

                            objs.add(make_shared<sphere>(point3( x, y, z), radius, matt));
                        }

                        if(material == "diffuse_light"){
                            std::getline(file, currentLine);


                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> r >> g >> b;
                            auto matt = make_shared<diffuse_light>(color(r, g, b));

                            std::getline(file, currentLine);


                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> radius;                            

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> x >> y >> z;

                            objs.add(make_shared<sphere>(point3(x, y, z), radius, matt));   
       
                        }
                    }
               
                    if(currentLine == "object_moving_sphere"){

                        std::getline(file, currentLine);


                        iss.clear();
                        iss.str(currentLine);
                        iss >> keyword;
                        iss >> material;

                        if(material == "lambertian"){
                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> r >> g >> b;
                            auto matt = make_shared<lambertian>(color(r, g, b));

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> radius;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> x >> y >> z;
                            
                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> x2 >> y2 >> z2;

                            objs.add(make_shared<moving_sphere>(point3(x, y, z), point3(x2, y2, z2), 0, 1, radius, matt));
                        }
                        
                        if(material == "dielectric"){
                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> diaCoef;
                                                
                            auto matt = make_shared<dielectric>(diaCoef);

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> radius;                            


                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> x >> y >> z;

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> x2 >> y2 >> z2;

                            objs.add(make_shared<moving_sphere>(point3(x, y, z), point3(x2, y2, z2), 0, 1, radius, matt));
                        }

                        if(material == "metal"){
                            std::getline(file, currentLine);


                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> r >> g >> b;
                            
                            std::getline(file, currentLine);


                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> metalCoef;

                            auto matt = make_shared<metal>(color(r, g, b), metalCoef);

                            std::getline(file, currentLine);


                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> radius;                            



                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> x >> y >> z;

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> x2 >> y2 >> z2;

                            objs.add(make_shared<moving_sphere>(point3(x, y, z), point3(x2, y2, z2), 0, 1, radius, matt));
                        }

                        if(material == "diffuse_light"){
                            std::getline(file, currentLine);


                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> r >> g >> b;
                            auto matt = make_shared<diffuse_light>(color(r, g, b));

                            std::getline(file, currentLine);


                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> radius;                            

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> x >> y >> z;

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> x2 >> y2 >> z2;

                            objs.add(make_shared<moving_sphere>(point3(x, y, z), point3(x2, y2, z2), 0, 1, radius, matt));
       
                        }
                    }               
               
                    if(currentLine == "object_yz_rect"){
                        std::getline(file, currentLine);

                        iss.clear();
                        iss.str(currentLine);
                        iss >> keyword;
                        iss >> material;

                        if(material == "lambertian"){
                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> r >> g >> b;
                            auto matt = make_shared<lambertian>(color(r, g, b));

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> minx;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> maxx;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> miny;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> maxy;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> zrec;

                            objs.add(make_shared<yz_rect>(minx, maxx, miny, maxy, zrec, matt));
                        }
                        
                        if(material == "dielectric"){
                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> diaCoef;
                                                
                            auto matt = make_shared<dielectric>(diaCoef);

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> minx;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> maxx;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> miny;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> maxy;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> zrec;

                            objs.add(make_shared<yz_rect>(minx, maxx, miny, maxy, zrec, matt));
                        }

                        if(material == "metal"){
                            std::getline(file, currentLine);


                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> r >> g >> b;
                            
                            std::getline(file, currentLine);


                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> metalCoef;

                            auto matt = make_shared<metal>(color(r, g, b), metalCoef);

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> minx;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> maxx;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> miny;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> maxy;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> zrec;

                            objs.add(make_shared<yz_rect>(minx, maxx, miny, maxy, zrec, matt));
                        }

                        if(material == "diffuse_light"){
                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> r >> g >> b;
                            auto matt = make_shared<diffuse_light>(color(r, g, b));

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> minx;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> maxx;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> miny;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> maxy;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> zrec;

                            objs.add(make_shared<yz_rect>(minx, maxx, miny, maxy, zrec, matt));
       
                        }
                    }               
                              
                    if(currentLine == "object_xz_rect"){
                        std::getline(file, currentLine);

                        iss.clear();
                        iss.str(currentLine);
                        iss >> keyword;
                        iss >> material;

                        if(material == "lambertian"){
                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> r >> g >> b;
                            auto matt = make_shared<lambertian>(color(r, g, b));

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> minx;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> maxx;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> miny;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> maxy;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> zrec;

                            objs.add(make_shared<xz_rect>(minx, maxx, miny, maxy, zrec, matt));
                        }
                        
                        if(material == "dielectric"){
                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> diaCoef;
                                                
                            auto matt = make_shared<dielectric>(diaCoef);

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> minx;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> maxx;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> miny;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> maxy;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> zrec;

                            objs.add(make_shared<xz_rect>(minx, maxx, miny, maxy, zrec, matt));
                        }

                        if(material == "metal"){
                            std::getline(file, currentLine);


                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> r >> g >> b;
                            
                            std::getline(file, currentLine);


                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> metalCoef;

                            auto matt = make_shared<metal>(color(r, g, b), metalCoef);

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> minx;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> maxx;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> miny;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> maxy;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> zrec;

                            objs.add(make_shared<xz_rect>(minx, maxx, miny, maxy, zrec, matt));
                        }

                        if(material == "diffuse_light"){
                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> r >> g >> b;
                            auto matt = make_shared<diffuse_light>(color(r, g, b));

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> minx;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> maxx;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> miny;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> maxy;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> zrec;

                            objs.add(make_shared<xz_rect>(minx, maxx, miny, maxy, zrec, matt));
       
                        }
                    }                   
               
                    if(currentLine == "object_xy_rect"){
                        std::getline(file, currentLine);

                        iss.clear();
                        iss.str(currentLine);
                        iss >> keyword;
                        iss >> material;

                        if(material == "lambertian"){
                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> r >> g >> b;
                            auto matt = make_shared<lambertian>(color(r, g, b));

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> minx;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> maxx;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> miny;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> maxy;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> zrec;

                            objs.add(make_shared<xy_rect>(minx, maxx, miny, maxy, zrec, matt));
                        }
                        
                        if(material == "dielectric"){
                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> diaCoef;
                                                
                            auto matt = make_shared<dielectric>(diaCoef);

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> minx;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> maxx;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> miny;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> maxy;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> zrec;

                            objs.add(make_shared<xy_rect>(minx, maxx, miny, maxy, zrec, matt));
                        }

                        if(material == "metal"){
                            std::getline(file, currentLine);


                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> r >> g >> b;
                            
                            std::getline(file, currentLine);


                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> metalCoef;

                            auto matt = make_shared<metal>(color(r, g, b), metalCoef);

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> minx;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> maxx;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> miny;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> maxy;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> zrec;

                            objs.add(make_shared<xy_rect>(minx, maxx, miny, maxy, zrec, matt));
                        }

                        if(material == "diffuse_light"){
                            std::getline(file, currentLine);
                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> r >> g >> b;
                            auto matt = make_shared<diffuse_light>(color(r, g, b));

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> minx;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> maxx;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> miny;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> maxy;

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> zrec;

                            objs.add(make_shared<xy_rect>(minx, maxx, miny, maxy, zrec, matt));
       
                        }
                    }                      

                    if(currentLine == "object_box"){
                        
                        std::getline(file, currentLine);


                        iss.clear();
                        iss.str(currentLine);
                        iss >> keyword;
                        iss >> material;

                        if(material == "lambertian"){
                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> r >> g >> b;
                            auto matt = make_shared<lambertian>(color(r, g, b));

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> x >> y >> z;
                            
                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> x2 >> y2 >> z2;

                            objs.add(make_shared<box>(point3(x, y, z), point3(x2, y2, z2), matt));
                        }
                        
                        if(material == "dielectric"){
                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> diaCoef;
                                                
                            auto matt = make_shared<dielectric>(diaCoef);

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> x >> y >> z;
                            
                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> x2 >> y2 >> z2;

                            objs.add(make_shared<box>(point3(x, y, z), point3(x2, y2, z2), matt));
                        }

                        if(material == "metal"){
                            std::getline(file, currentLine);


                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> r >> g >> b;
                            
                            std::getline(file, currentLine);


                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> metalCoef;

                            auto matt = make_shared<metal>(color(r, g, b), metalCoef);

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> x >> y >> z;
                            
                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> x2 >> y2 >> z2;

                            objs.add(make_shared<box>(point3(x, y, z), point3(x2, y2, z2), matt));
                        }

                        if(material == "diffuse_light"){
                            std::getline(file, currentLine);

                            std::cout << "we got boooox" << std::endl;
                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> r >> g >> b;
                            auto matt = make_shared<diffuse_light>(color(r, g, b));

                            std::getline(file, currentLine);

                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> x >> y >> z;
                            
                            iss.clear();
                            iss.str(currentLine);
                            iss >> keyword;
                            iss >> x2 >> y2 >> z2;

                            objs.add(make_shared<box>(point3(x, y, z), point3(x2, y2, z2), matt));
       
                        }
                    }       
                }
                if(currentLine == "BIMAGEPARAMS"){

                    std::getline(file, currentLine);

                    iss.clear();
                    iss.str(currentLine);
                    iss >> keyword;
                    iss >> aspectNum;
                    iss >> opera;
                    iss >> aspectDen;

                    aspect_ratio =  aspectNum / aspectDen;

                    
                    std::getline(file, currentLine);

                    iss.clear();
                    iss.str(currentLine);
                    iss >> keyword;
                    iss >> image_width;
                    image_height = static_cast<int>(image_width / aspect_ratio);

                    
                    std::getline(file, currentLine);

                    iss.clear();
                    iss.str(currentLine);
                    iss >> keyword;
                    iss >> samples_per_pixel;

                    std::getline(file, currentLine);


                    iss.clear();
                    iss.str(currentLine);
                    iss >> keyword;
                    iss >> max_depth;

                }
                if(currentLine == "BCAMERAPARAMS"){

                    std::getline(file, currentLine);


                    iss.clear();
                    iss.str(currentLine);
                    iss >> keyword;
                    iss >> fromx >> fromy >> fromz;

                    std::getline(file, currentLine);

                    iss.clear();
                    iss.str(currentLine);
                    iss >> keyword;
                    iss >> atx >> aty >> atz;

                    std::getline(file, currentLine);


                    iss.clear();
                    iss.str(currentLine);
                    iss >> keyword;
                    iss >> vupx >> vupy >> vupz;


                    std::getline(file, currentLine);

                    iss.clear();
                    iss.str(currentLine);
                    iss >> keyword;
                    iss >> vfov;

                    
                    std::getline(file, currentLine);


                    iss.clear();
                    iss.str(currentLine);
                    iss >> keyword;
                    iss >> aperture;

                    
                    std::getline(file, currentLine);


                    iss.clear();
                    iss.str(currentLine);
                    iss >> keyword;
                    iss >> dist_to_focus;

                    
                    std::getline(file, currentLine);


                    iss.clear();
                    iss.str(currentLine);
                    iss >> keyword;
                    iss >> br >> bg >> bb;


                    std::getline(file, currentLine);

                    iss.clear(); 
                    iss.str(currentLine);
                    iss >> keyword;
                    iss >> skylight;

                }                
                std::getline(file, currentLine);
                currentLine.erase(std::remove_if(currentLine.begin(), currentLine.end(), ::isspace), currentLine.end());
            }      
        }
        
        // Close the file
        file.close();

        this->cam_frompoint = point3(fromx, fromy, fromz);
        this->cam_vups = vec3(vupx, vupy, vupz);
        this->cam_vfov = vfov;
        this->cam_aspect_ratio = aspect_ratio;
        this->cam_aperature = aperture;
        this->cam_dist_to_focus = dist_to_focus;

        this->im_w = image_width;
        this->im_h = image_height;
        this->im_spp = samples_per_pixel;
        this->im_max_depth = max_depth;

        this->im_bc = color(br, bg, bb);
        this->im_skylight = skylight;
        this->objs = objs;

}