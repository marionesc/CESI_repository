package com.marionesc.additivemanufacturinggesture.Element;

import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.io.*;


public class RawMaterialsList {
    private ArrayList<RawMaterials> RawMaterialsList;

    public RawMaterialsList() {
        RawMaterialsList = new ArrayList<>();
    }

    public void addRawMaterials(String name, String printType, String color, int stock, double price, String commentary) {
        RawMaterials init_rw = new RawMaterials(name, printType, color, stock, price, commentary);
        RawMaterialsList.add(init_rw);
    }

    /** **/
    public void setPrint()  {
        for (RawMaterials init_rw: RawMaterialsList) {
            System.out.println(init_rw.toString());
        }
    }

    /** **/
    public ArrayList<RawMaterials> getRawMaterialsList() {
        return RawMaterialsList;
    }

    /** **/
    public void setRawMaterialsList(ArrayList<RawMaterials> RawMaterialsList) {
        this.RawMaterialsList = RawMaterialsList;
    }

    /** **/
    public void saveToCSV(String filename) {
        try {
            boolean fileExists = Files.exists(Paths.get(filename));
            PrintWriter writer = new PrintWriter(new FileWriter(filename, true));

            // Check if the file exists and it's empty, then write the header line
            if (!fileExists || Files.size(Paths.get(filename)) == 0) {
                writer.println("Name, printType, Color, Stock, Price, Commentary"); // Write header line
            }

            for (RawMaterials RawMaterials : RawMaterialsList) {
                // Check if the beer with the same name already exists in the file
                boolean RowMaterialsExists = false;
                if (fileExists) {
                    try (BufferedReader reader = new BufferedReader(new FileReader(filename))) {
                        String line;
                        while ((line = reader.readLine()) != null) {
                            if (line.startsWith(RawMaterials.getName() + ",")) {
                                RowMaterialsExists = true;
                                break;
                            }
                        }
                    }
                }

                // If the beer doesn't exist, write it to the CSV file
                if (!RowMaterialsExists) {
                    writer.println(RawMaterials.getName() + "," +
                                   RawMaterials.getPrintType() + "," +
                                   RawMaterials.getColor() + "," +
                                   RawMaterials.getStock() + "," +
                                   RawMaterials.getPrice() + "," +
                                   RawMaterials.getCommentary());
                }
            }

            writer.close();
        } catch (IOException e) {
            System.err.println("Error saving Raw Material list to CSV: " + e.getMessage());
        }
    }

    /** **/
    public void loadFromCSV(String filename) {
        try (BufferedReader reader = new BufferedReader(new FileReader(filename))) {
            String line = reader.readLine(); // Read the header line and discard it

            //  addRawMaterials(String name, String printType, String color, int stock, double price)
            while ((line = reader.readLine()) != null) {
                String[] RawMaterialsData = line.split(",");
                if (RawMaterialsData.length == 6) {
                    String name         = RawMaterialsData[0].trim();
                    String printType    = RawMaterialsData[1].trim();
                    String color        = RawMaterialsData[2].trim();
                    double stock        = Double.parseDouble(RawMaterialsData[3].trim());
                    double price        = Double.parseDouble(RawMaterialsData[4].trim());
                    String commentary   = RawMaterialsData[5].trim();

                    RawMaterials rawMaterials = new RawMaterials(name, printType, color,stock, price, commentary);
                    RawMaterialsList.add(rawMaterials);

                } else {
                    System.err.println("Invalid CSV format: " + line);
                }
            }
        } catch (IOException e) {
            System.err.println("Error loading beer list from CSV: " + e.getMessage());
        } catch (NumberFormatException e) {
            System.err.println("Error parsing numeric value in CSV: " + e.getMessage());
        }
    }

    /** **/
    public void deleteRawMaterials(String filename, String rawMaterials_name) {
        ArrayList<RawMaterials> updatedList = new ArrayList<>();

        try (BufferedReader reader = new BufferedReader(new FileReader(filename))) {
            String line = reader.readLine(); // Read the header line and discard it

            while ((line = reader.readLine()) != null) {
                String[] rw_data = line.split(",");
                if (rw_data.length == 6) {
                    String name = rw_data[0].trim();

                    if (!name.equals(rw_data)) {
                        String printType    = rw_data[1].trim();
                        String color        = rw_data[2].trim();
                        double stock        = Double.parseDouble(rw_data[3].trim());
                        double price        = Double.parseDouble(rw_data[4].trim());
                        String commentary   = rw_data[5].trim();

                        RawMaterials rawMaterials = new RawMaterials(name, printType, color, stock, price, commentary);
                        updatedList.add(rawMaterials);
                    }
                } else {
                    System.err.println("Invalid CSV format: " + line);
                }
            }
        }

        catch (IOException e) {
            System.err.println("Error deleting raw materials from CSV: " + e.getMessage());
            return;  // Exit the method if an error occurs
        }

        catch (NumberFormatException e) {
            System.err.println("Error parsing numeric value in CSV: " + e.getMessage());
            return;  // Exit the method if an error occurs
        }

        try (PrintWriter writer = new PrintWriter(new FileWriter(filename))) {
            for (RawMaterials rawMaterials : updatedList) {
                writer.println(rawMaterials.getName() + "," +
                                rawMaterials.getPrintType() + "," +
                                rawMaterials.getColor() + "," +
                                rawMaterials.getStock() + "," +
                                rawMaterials.getPrice() + "," +
                                rawMaterials.getCommentary());
            }
        } catch (IOException e) {
            System.err.println("Error updating raw materials list in CSV: " + e.getMessage());
        }
    }

}


