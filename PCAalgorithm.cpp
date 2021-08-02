//
// Created by xtn on 2020/05/11.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "PCAalgorithm.h"
#include "Eigen/Eigenvalues"




void nhmcla003::PCAalgorithm::pcaAlgorithm(){
    std::vector<double> january = {51.2, 51.2, 39.5, 45.1, 29.9, 24.8, 32, 35.6, 54.6, 67.2, 42.4, 29, 22.9, 23.8, 27.9, 19.4, 31.3, 33.3, 52.9, 21.5, 33.4, 29.2, 25.5, 14.2, 8.5, 12.2, 47.1, 27.8, 31.3, 20.5, 22.6, 31.9, 20.6, 32.7, 35.2, 21.5, 23.7, 32.2, 42.1, 40.5, 8.2, 31.1, 26.9, 28.4, 36.8, 38.1, 32.3, 28.1, 28.4, 45.4, 14.2, 40.5, 38.3, 44.8, 43.6, 52.1, 28, 16.8, 40.5, 37.5, 25.4, 34.5, 19.4, 26.6};
    std::vector<double> june  = {81.6, 91.2, 81.4, 75.2, 73, 72.7, 75.8, 78.7, 81, 82.3, 78, 74.5, 71.9, 75.1, 75, 75.1, 80.7, 76.9, 81.9, 68, 76.6, 73.3, 73.3, 63.8, 65.6, 71.9, 81.7, 78.8, 78.6, 69.3, 77.2, 69.3, 69.7, 75.1, 78.7, 72, 70.1, 76.6, 78.5, 77.5, 70.8, 75.6, 71.4, 73.6, 81.5, 67.1, 76.8, 71.9, 72.1, 81.2, 73.3, 79.6, 79.6, 84.8, 82.3, 83.3, 76.7, 69.8, 78.3, 77.9, 69.7, 75, 69.9, 69.1};

    // calculate the mean  of  each dataset
    double mean1=findmean(january);
    double mean2=findmean(june);

    //adjust vector values so that the mean is 0
    adjustmean(january,mean1);
    adjustmean(june,mean2);



    // Calculating and assigning values to the convariance matrix
    Eigen::MatrixXd matrix(2,2);
    matrix(0,0)=covariance(january,january) ;
    matrix(1,0)=covariance(january,june) ;
    matrix(0,1)=covariance(june,january) ;
    matrix(1,1)=covariance(june,june) ;





    //writing results to terminal
    Eigen::EigenSolver<Eigen::MatrixXd> es(matrix);
    std::cout << "1. What are the Eigenvalues for the principal components 1 and 2? :" << std::endl << es.eigenvalues().real() <<std::endl;
    std::cout << "2. What are the Eigenvectors for the principal components 1 and 2 (showing\n"
                 "July and January component values for each)? :" << std::endl << es.eigenvectors().real() << std::endl ;

    double variance=matrix(0,0)+matrix(1,1);

    std::cout<<"3. Compute the values for the covariance matrix : \n"<<matrix<<std::endl;
    std::cout<<"4. What is the total variance? :\n"<<variance<<std::endl;

    std::cout<< "5. What proportion (as a percentage) of total variance do principal components 1  :\n"<<((es.eigenvalues().real()[0]/variance)*100)<<"%"<<std::endl;
    std::cout<< " What proportion (as a percentage) of total variance do principal components 2  :\n"<<((es.eigenvalues().real()[1]/variance)*100)<<"%"<<std::endl;
    std::cout<< "The results show that principal 1(january) explains "<<((es.eigenvalues().real()[0]/variance)*100)<<"%"<<" of the variability meaning january data is more variable while Principal 2(june) explains  "<<((es.eigenvalues().real()[1]/variance)*100)<<"% of the variability meaning more variable"<<std::endl;




    //writing the answers to a text file
    std::ofstream  out ("results.txt");//Print the results  to a file results.txt
    out<<"Writing results to file--"<<"results.txt"<<std::endl;
    out << "1. What are the Eigenvalues for the principal components 1 and 2? :" << std::endl << es.eigenvalues().real() <<std::endl;
    out << "2. What are the Eigenvectors for the principal components 1 and 2 (showing\n"
           "July and January component values for each)? :" << std::endl << es.eigenvectors().real() << std::endl;
    out<<"3. Compute the values for the covariance matrix : \n"<<matrix<<std::endl;
    out<<"4. What is the total variance? :\n"<<variance<<std::endl;
    out<< "5. What proportion (as a percentage) of total variance do principal components 1  :\n"<<((es.eigenvalues().real()[0]/variance)*100)<<"%"<<std::endl;
    out<< " What proportion (as a percentage) of total variance do principal components 2  :\n"<<((es.eigenvalues().real()[1]/variance)*100)<<"%"<<std::endl;
    out<< "The results show that principal 1(january) explains "<<((es.eigenvalues().real()[0]/variance)*100)<<"%"<<" of the variability meaning january data is more variable while Principal 2(june) explains  "<<((es.eigenvalues().real()[1]/variance)*100)<<"% of the variability meaning more variable"<<std::endl;


    out.close();
    std::cout<<"Answers written to results.txt"<<std::endl;



    //double convariencexx = covariance(january, june);



}


double nhmcla003::PCAalgorithm::findmean(const std::vector<double>& data){
    //calculate mean  and return the answer
    double result=0;

    //calculate  mean
    for (int i = 0; i <data.size() ; ++i) {
        result+=data[i];
    }

    return result/data.size();
}

void nhmcla003::PCAalgorithm::adjustmean(std::vector<double>& data,const double& mean){
    //Adjust the values of the array so that the mean is zero
    for (int i = 0; i < data.size(); ++i) {
        data[i]=data[i]-mean;
    }
}

double nhmcla003::PCAalgorithm::covariance(const std::vector<double>& data,const std::vector<double>& data2){
    //calculate  the covariance and return
    double result=0;

    for (int i = 0; i <data.size() ; ++i) {
        result+=data[i]*data2[i];
    }

    return result/(data.size()-1);
}