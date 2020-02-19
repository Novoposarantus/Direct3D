#include "Box2.h"

Box2::Box2(
	Graphics& gfx, 
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
	float sizeZ, 
	Drawable* parent)
	: Box (
		gfx,
		r,
		droll,
		dpitch,
		dyaw,
		dphi,
		dtheta,
		dchi,
		chi,
		theta,
		phi,
		sizeX,
		sizeY,
		sizeZ
	),
	boxParent(parent)
{}

DirectX::XMMATRIX Box2::GetTransformXM() const noexcept
{
	namespace dx = DirectX;

	dx::XMVECTOR outScale;
	dx::XMVECTOR outRotQuat;
	dx::XMVECTOR outTrans;
	auto a = boxParent->GetTransformXM();
	dx::XMMatrixDecompose(
		&outScale,
		&outRotQuat,
		&outTrans,
		a
	);
	dx::XMFLOAT3 trans;
	dx::XMStoreFloat3(&trans, outTrans);

	return dx::XMLoadFloat3x3(&mt) *
		dx::XMMatrixRotationRollPitchYaw(pitch, yaw, roll) *
		dx::XMMatrixTranslation(r, 0.0f, 0.0f) *
		dx::XMMatrixRotationRollPitchYaw(theta, phi, chi) *
		dx::XMMatrixTranslation(trans.x, trans.y, trans.z);
}


