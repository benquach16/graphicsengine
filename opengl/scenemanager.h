#ifndef _SCENEMANAGER_H_
#define _SCENEMANAGER_H_

#pragma once


#include "quaternion.h"
#include "vector2d.h"
#include "vector3d.h"
#include "mesh.h"
#include "meshloader.h"
#include "imageloader.h"

class CSceneManager
{
public:
	friend class CSceneNode;
	friend class CCameraSceneNode;
	friend class CMeshSceneNode;
	friend class CLightSceneNode;
	//create everything
	CSceneManager();
	~CSceneManager();
	void render();

	//mutator
	void setNewActiveCamera(CCameraSceneNode *new_camera)
	{
		active_camera = new_camera;
	}
	CCameraSceneNode *getActiveCamera()
	{
		return active_camera;
	}
	
	//create a box and child it
	CMeshSceneNode *createBoxSceneNode(float size = 1.0f,
		vector3d position = vector3d(0,0,0),
		vector3d rotation = vector3d(0,0,0),
		vector3d scale = vector3d(1,1,1),
		CSceneNode *parent = 0);
	//same thing but with a sphere
	CMeshSceneNode *createSphereSceneNode(float radius = 1.0f,
		int num_triangles = 16,
		vector3d position = vector3d(0,0,0),
		vector3d rotation = vector3d(0,0,0),
		vector3d scale = vector3d(1,1,1),
		CSceneNode *parent = 0);
	//create a mesh
	CMeshSceneNode *createMeshSceneNode(CMesh *mesh = 0,
		vector3d position = vector3d(0,0,0),
		vector3d rotation = vector3d(0,0,0),
		vector3d scale = vector3d(1,1,1),
		CSceneNode *parent = 0);
	//create a camera and child it
	CCameraSceneNode *createCameraSceneNode(vector3d position = vector3d(0,0,0),
		vector3d rotation = vector3d(0,0,0),
		CSceneNode *parent = 0);
	//create a light and child it
	CLightSceneNode *createLightSceneNode(float strength = 200.f,
		float radius = 100.f,
		vector3d position = vector3d(0,0,0),
		vector3d rotation = vector3d(0,0,0),
		const color newcolor = color(255,255,255,255),
		CSceneNode* parent = 0);

	//accessor function

	const CSceneNode *getRootSceneNode() const
	{
		return root;
	}
	CSceneNode *getRootSceneNode()
	{
		return root;
	}

private:

	//all scene nodes must be childed to this root
	CSceneNode *root;

	//There can be only one active camera
	CCameraSceneNode *active_camera;


};


#endif
