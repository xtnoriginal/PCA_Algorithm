//
// Created by xtn on 2020/05/11.
//

#ifndef ASSIGNMENT5_PCAALGORITHM_H
#define ASSIGNMENT5_PCAALGORITHM_H


namespace  nhmcla003 {
    class PCAalgorithm {
    private:
        std::string results;


    public:


        void pcaAlgorithm();

        double findmean(const std::vector<double> &data);

        double covariance(const std::vector<double> &data, const std::vector<double> &data2);

        void adjustmean(std::vector<double> &data,const double& mean);


        void readFile(const std::string &filename);
    };

}


#endif //ASSIGNMENT5_PCAALGORITHM_H
