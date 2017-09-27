package com.dylansecreast.core;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionAdapter;
import java.util.ArrayList;

import javax.swing.JPanel;

public class Canvas extends JPanel{
	
	private static final long serialVersionUID = 1L;
	private ArrayList<CanvasPoints> _points;
	private Color _currentColor;
	private int _currentSize;
	
	public Canvas() {
		_points = new ArrayList<>();
		_currentColor = Color.BLACK;
		_currentSize = 12;
		
		addMouseMotionListener(new MouseMotionAdapter() {
			@Override
			public void mouseDragged(MouseEvent e) {
				int x = e.getPoint().x;
				int y = e.getPoint().y;
				_points.add(new CanvasPoints(x, y, _currentSize, _currentColor));
				repaint();
			}
		});	
		
		addMouseListener(new MouseListener() {
			@Override
			public void mouseClicked(MouseEvent e) {
				int x = e.getPoint().x;
				int y = e.getPoint().y;
				_points.add(new CanvasPoints(x, y, _currentSize, _currentColor));
				repaint();
			}

			@Override
			public void mouseEntered(MouseEvent arg0) {
				// TODO Auto-generated method stub
			}

			@Override
			public void mouseExited(MouseEvent arg0) {
				// TODO Auto-generated method stub
			}

			@Override
			public void mousePressed(MouseEvent arg0) {
				// TODO Auto-generated method stub
			}

			@Override
			public void mouseReleased(MouseEvent arg0) {
				// TODO Auto-generated method stub
			}
		});
 		
	}	// end Canvas()
	
	public void setColor(Color c) {
		_currentColor = c;
	}
	
	public void setSize(int newSize) {
		_currentSize = newSize;
	}
	
	public void clearList() {
		_points.clear();
		repaint();
	}
	
	@Override
	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		for (CanvasPoints point : _points) {
			g.setColor(point.getColor());
			g.fillOval(point.x, point.y, point.getSize(), point.getSize());
		}

	}	// end paintComponent()

}	// end class Canvas
