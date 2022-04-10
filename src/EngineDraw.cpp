#include "Engine.h"

void Engine::Draw()
{
	glClearColor(0.0f, 0.5f, 1.0f, 1.0f);
	//Clear the screen
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_DEPTH_BUFFER_BIT);

	//Draw the ground
	glUseProgram(sh.GetId());
	//Calculate the view matrix
	glm::mat4 viewMatrix = glm::translate(glm::mat4(1.0f), -cameraPosition);
	glm::mat4 rotationViewMatrix = glm::mat4
	(
		glm::cos(cameraRotation), 0.0f, -glm::sin(cameraRotation), 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		glm::sin(cameraRotation), 0.0f, glm::cos(cameraRotation), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
	glm::mat4 scaleMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(mapXSize, 1.0f, mapZSize));
	glm::mat4 modelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -1.5f, 0.0f));
	glm::mat4 modelViewMatrix = rotationViewMatrix * modelMatrix * viewMatrix * scaleMatrix;
	//Apply uniforms
	glUniformMatrix4fv(sh.GetUniformLocation("u_Perspective"), 1, false, glm::value_ptr(perspectiveMatrix));
	glUniformMatrix4fv(sh.GetUniformLocation("u_ModelViewMatrix"), 1, false, glm::value_ptr(modelViewMatrix));
	glUniform4f(sh.GetUniformLocation("u_Color"), 0.0f, 0.8f, 0.0f, 1.0f);

	glDrawArrays(GL_TRIANGLES, 0, vb.VertexCount());

	//Draw the maze
	glm::mat4 rotX = glm::mat4
	(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, glm::cos(theta), -glm::sin(theta), 0.0f,
		0.0f, glm::sin(theta), glm::cos(theta), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
	glm::mat4 rotZ = glm::mat4
	(
		glm::cos(theta), -glm::sin(theta), 0.0f, 0.0f,
		glm::sin(theta), glm::cos(theta), 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);

	//Draw the walls
	scaleMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(wallSize, 3.0f, wallSize));
	for(auto w : maze)
	{
		modelMatrix = glm::translate(glm::mat4(1.0f), w);
		modelViewMatrix = rotationViewMatrix * modelMatrix * viewMatrix * scaleMatrix;

		//Apply uniforms
		glUniformMatrix4fv(sh.GetUniformLocation("u_ModelViewMatrix"), 1, false, glm::value_ptr(modelViewMatrix));
		glUniform4f(sh.GetUniformLocation("u_Color"), 0.5f, 0.5f, 0.5f, 1.0f);

		glDrawArrays(GL_TRIANGLES, 0, vb.VertexCount());
	}

	//Draw the coins
	scaleMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(0.2f, 0.2f, 0.2f));
	for(auto c : coins)
	{
		modelMatrix = glm::translate(glm::mat4(1.0f), c);
		modelViewMatrix = rotationViewMatrix * modelMatrix * viewMatrix * scaleMatrix * rotX * rotZ;

		//Apply uniforms
		glUniformMatrix4fv(sh.GetUniformLocation("u_ModelViewMatrix"), 1, false, glm::value_ptr(modelViewMatrix));
		glUniform4f(sh.GetUniformLocation("u_Color"), 1.0f, 1.0f, 0.0f, 1.0f);

		glDrawArrays(GL_TRIANGLES, 0, vb.VertexCount());
	}

	//Draw the exit
	glUseProgram(rainbowSh.GetId());

	scaleMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(0.4f, 0.4f, 0.4f));
	modelMatrix = glm::translate(glm::mat4(1.0f), exitPos);
	modelViewMatrix = rotationViewMatrix * modelMatrix * viewMatrix * scaleMatrix * rotX * rotZ;
	//Apply uniforms
	glUniformMatrix4fv(rainbowSh.GetUniformLocation("u_Perspective"), 1, false, glm::value_ptr(perspectiveMatrix));
	glUniformMatrix4fv(rainbowSh.GetUniformLocation("u_ModelViewMatrix"), 1, false, glm::value_ptr(modelViewMatrix));

	glDrawArrays(GL_TRIANGLES, 0, vb.VertexCount());

	//Swap the buffers in the window
	glfwSwapBuffers(glWindow);
}