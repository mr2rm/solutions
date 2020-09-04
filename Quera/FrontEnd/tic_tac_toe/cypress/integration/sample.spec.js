describe('Sample Test:', () => {
  it('check game rules', () => {
    cy.visit('index.html');
    cy.get('.cell[data-cell-index="0"]').click();
    cy.get('.cell[data-cell-index="1"]').click();
    cy.get('.cell[data-cell-index="3"]').click();
    cy.get('.cell[data-cell-index="4"]').click();
    cy.get('.cell[data-cell-index="6"]').click();
    cy.get('.cell[data-cell-index="5"]').click().should('have.text', '');

    cy.get('.game--status')
      .should('contain', 'X')
      .should('not.contain', 'O')
      .should('contain', 'won');

    cy.get('.game--restart').click();

    cy.get('.game--status')
      .should('contain', 'X')
      .should('not.contain', 'O')
      .should('contain', 'turn');

    cy.get('.cell[data-cell-index="0"]').click();
    cy.get('.cell[data-cell-index="2"]').click();
    cy.get('.cell[data-cell-index="8"]').click();
    cy.get('.cell[data-cell-index="4"]').click();
    cy.get('.cell[data-cell-index="5"]').click();
    cy.get('.cell[data-cell-index="6"]').click();

    cy.get('.game--status')
      .should('contain', 'O')
      .should('not.contain', 'X')
      .should('contain', 'won');

    cy.visit('index.html');
    cy.get('.cell[data-cell-index="0"]').click();
    cy.get('.cell[data-cell-index="3"]').click();
    cy.get('.cell[data-cell-index="1"]').click();
    cy.get('.cell[data-cell-index="4"]').click();
    cy.get('.cell[data-cell-index="2"]').click();
    cy.get('.cell[data-cell-index="5"]').click().should('have.text', '');

    cy.get('.game--status')
      .should('contain', 'X')
      .should('not.contain', 'O')
      .should('contain', 'won');

    cy.get('.game--restart').click();

    cy.get('.game--status')
      .should('contain', 'X')
      .should('not.contain', 'O')
      .should('contain', 'turn');

    cy.get('.cell[data-cell-index="0"]').click();
    cy.get('.cell[data-cell-index="1"]').click();
    cy.get('.cell[data-cell-index="2"]').click();
    cy.get('.cell[data-cell-index="3"]').click();
    cy.get('.cell[data-cell-index="7"]').click();
    cy.get('.cell[data-cell-index="8"]').click();
    cy.get('.cell[data-cell-index="5"]').click();
    cy.get('.cell[data-cell-index="4"]').click();
    cy.get('.cell[data-cell-index="6"]').click();

    cy.get('.game--status')
      .should('contain', 'draw')
      .should('not.contain', 'X')
      .should('not.contain', 'O');
  });
});
