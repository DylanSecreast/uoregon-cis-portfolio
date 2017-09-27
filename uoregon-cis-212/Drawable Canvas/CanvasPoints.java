package com.dylansecreast.core;

import java.awt.Color;
import java.awt.Point;

public class CanvasPoints extends Point {
	
	private static final long serialVersionUID = 1L;
	private Color _color;
	private int _pointSize;
	
	public CanvasPoints(int xCoord, int yCoord, int size, Color color) {
		super(xCoord, yCoord);
		_pointSize = size;
		_color = color;
	}
	
	public Color getColor() {
		return _color;
	}
	
	public int getSize() {
		return _pointSize;
	}
	
	public Point getPosition() {
		return super.getLocation();
	}
	
}
