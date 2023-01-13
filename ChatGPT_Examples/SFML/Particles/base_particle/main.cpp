/* */
#include <SFML/Graphics.hpp>

const int NUM_PARTICLES = 1000;

struct Particle {
  sf::Vector2f position;
  sf::Vector2f velocity;
  sf::Color color;
  float lifetime;
};

Particle particles[NUM_PARTICLES];

void updateParticles(float dt) {
  for (int i = 0; i < NUM_PARTICLES; i++) {
    // Update the position of the particle based on its velocity
    particles[i].position += particles[i].velocity * dt;

    // Apply gravity and friction to the particle's velocity
    particles[i].velocity.y += 1000.0f * dt;  // gravity
    particles[i].velocity *= 0.99f;  // friction

    // Reduce the lifetime of the particle
    particles[i].lifetime -= dt;

    // If the particle's lifetime has expired, reset its position and velocity
    if (particles[i].lifetime <= 0.0f) {
      particles[i].position = sf::Vector2f(400, 300);  // reset position
      particles[i].velocity = sf::Vector2f(rand() % 400 - 200, -(rand() % 500));  // random velocity
      particles[i].lifetime = (float)(rand() % 1000) / 1000.0f + 0.5f;  // random lifetime
      particles[i].color = sf::Color(rand() % 255, rand() % 255, 0);  // random color
    }
  }
}

void drawParticles(sf::RenderWindow& window) {
  for (int i = 0; i < NUM_PARTICLES; i++) {
    sf::CircleShape shape(2.0f);
    shape.setPosition(particles[i].position);
    shape.setFillColor(particles[i].color);
    window.draw(shape);
  }
}

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "Particle System");
  sf::Clock clock;

  // Initialize the particles
  for (int i = 0; i < NUM_PARTICLES; i++)
   {
    particles[i].position = sf::Vector2f(400, 300);  // center of the window
    particles[i].velocity = sf::Vector2f(rand() % 400 - 200, -(rand() % 500));  // random velocity
    particles[i].lifetime = (float)(rand() % 1000) / 1000.0f + 0.5f;  // random lifetime
    particles[i].color = sf::Color(rand() % 255, rand() % 255, 0);  // random color
  }

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    // Update the particles
    float dt = clock.restart().asSeconds();
    updateParticles(dt);

    // Clear the window
    window.clear(sf::Color::Black);

    // Draw the particles
    drawParticles(window);

    // Display the window
    window.display();
  }

  return 0;
}