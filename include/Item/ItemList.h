#pragma once
#include "pch.h"

#include <vector>
#include "ItemInfo.h"
#include "FFJson.h"

using namespace std;

class ItemList
{
public:
	ItemList();
	~ItemList();

	vector<int> itemList;
	vector<vector<float> > posList;

	class ItemInstance {
	public:
		ItemInstance(int categoryID, int idInSameCategory);
		~ItemInstance();
		int categoryID;
		int idInSameCategory;
		vector<float> pos;
	};
	vector<ItemInstance> instanceList;

	class CategoryInstance {
	public:
		CategoryInstance(int categoryId);
		CategoryInstance();
		int categoryId;
		int count;
		vector<float> posX;
		vector<float> posY;
		vector<float> posZ;
	};
	vector<CategoryInstance> categoryList;

	FFJson j_itemlist;


	int SetItemList(vector<int> itemList);
	int SetPosList(vector<vector<float> > posList);
	int GenInstanceList();
	int ConverInstanceList2Json();
	int GetCategoryList();

	int WriteCategoryListJsonFile(const char* FilePath);
	vector<CategoryInstance> ReadCateListJson(const char* FilePath); 
	int Compare(vector<int> des, vector<CategoryInstance> categoryList);
	vector<vector<float> > GetPosOfVectorIntByCategoryList(vector<int> vint, vector<CategoryInstance> categoryList);


};

