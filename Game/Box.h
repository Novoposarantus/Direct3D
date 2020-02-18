#pragma once
#include "DrawableBase.h"

class Box : public DrawableBase<Box>
{
public:
	Box( Graphics& gfx,
		float r,
		float droll,
		float dpitch,
		float dyaw,
		float dphi,
		float dtheta,
		float dchi,
		float chi,
		float theta,
		float phi,
		float sizeX,
		float sizeY,
		float sizeZ);
	void Update( float dt ) noexcept override;
	DirectX::XMMATRIX GetTransformXM() const noexcept override;
private:
	// positional
	float r;
	float roll = 0.0f;
	float pitch = 0.0f;
	float yaw = 0.0f;
	float theta;
	float phi;
	float chi;
	// speed (delta/s)
	float droll;
	float dpitch;
	float dyaw;
	float dtheta;
	float dphi;
	float dchi;
	// model transform
	DirectX::XMFLOAT3X3 mt;
};