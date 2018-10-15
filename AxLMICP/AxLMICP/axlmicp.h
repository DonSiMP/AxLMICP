#pragma once
#include <Eigen/Dense>
#include <unsupported/Eigen/NonLinearOptimization>
#include <string>
#include <vector>
#include "PointXYZ.h"
#include "../ANNd/ANN/ANN.h"


//using Eigen::MatrixXd;
using namespace Eigen;
using namespace Eigen::internal;
using namespace Eigen::Architecture;
using namespace std;
struct OptimizationFunctor;
class axlmicp
{
	typedef Eigen::Matrix<float, Eigen::Dynamic, 1> VectorX;
public:
	axlmicp(void);
	~axlmicp();
	axlmicp(vector<PointXYZ>  *model_, vector<PointXYZ> * data_, int itermax_, int critFun_);
	axlmicp(MatrixXf model_, MatrixXf data_, int itermax_, int critFun_);
	void align();
	void SaveAlignData(string filename);
public:
	vector<PointXYZ>  *ml_model;
	vector<PointXYZ>  *ml_data;
	int dimModel;
	int dimData;
	MatrixXf m_model;
	MatrixXf m_data;
	MatrixXf consporsone;

	bool m_useOdometry;
	double m_Threshold;//���������ֵ
	bool m_AutoSetTJD;
	bool m_useDistanceReject;
	double m_ThresRejectDistance;//������ֵ�޳�
	int miniter;//��С��������
	int maxiter;//����������
	int critFun;//�Ƚ�����׼��
	
};

