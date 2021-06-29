window.addEventListener('CookiebotOnDialogDisplay', function () {
  var b = 'DetailBodyContent',
      c = 'CybotCookiebotDialog',
      d = document,
      buttons = d.querySelectorAll('#' + c + 'Body a'),
      categories = d.getElementById(c + 'BodyLevelButtonsSelectPane'),
      details = [
          d.getElementById(c + 'BodyLevelDetailsButton'),
          d.getElementById(c + 'BodyButtonDetails'),
      ],
      parent = categories.parentNode,
      fieldset = d.createElement('fieldset'),
      legend = d.createElement('legend'),
      tabs = d.getElementById(c + b + 'Tabs'),
      tabpanel = document.getElementById(c + b + 'CookieContainerTypeDetails')
          .childNodes,
      types = d.getElementById(c + b + 'CookieContainerTypes');
  function setActive(elem) {
    var active = !1,
        c = elem.childNodes;
    for (var i = 0; i < c.length; i++) {
      active = /Selected/g.test(c[i].getAttribute('class')) ? !0 : !1;
      c[i].setAttribute('tabindex', active ? '0' : '-1');
      c[i].setAttribute('aria-selected', active ? 'true' : 'false');
    }
  }

  function addAccessibility(elem, a) {
    var ariaControls = 'CybotCookiebotDialogDetailBodyContent',
      c = elem.childNodes;
    ariaControls += a ? '' : 'CookieContainerTypeDetails';
    elem.setAttribute('role', 'tablist');
    a || elem.setAttribute('aria-orientation', 'vertical');

    for (var i = 0; i < c.length; i++) {
      c[i].setAttribute('role', 'tab');
      c[i].setAttribute('aria-controls', ariaControls);
      setActive(c[i].parentNode);
      c[i].addEventListener('click', function () {
        setActive(elem);
      });
    }
  }

  function setAriaExpanded(elem) {
    elem.setAttribute('aria-expanded', 'false');
    elem.addEventListener('click', function () {
      elem.setAttribute(
        'aria-expanded',
        elem.getAttribute('aria-expanded') === 'false' ? 'true' : 'false'
      );
    });
  }

  d.getElementById('CookiebotDialogStyle').innerHTML +=
  '.CybotCookiebotDialogBodyButton:focus{outline:1px solid #007bc2;}';
  legend.innerHTML = '';
  legend.style.display = 'none';
  parent.insertBefore(fieldset, parent.firstChild);
  fieldset.appendChild(legend);
  fieldset.appendChild(categories);
  d.getElementById(c + b).setAttribute('role', 'tabpanel');
  d.getElementById(c + 'BodyLevelButtonsTable').style.display = 'inline';

  for (var i = 0; i < details.length; i++) setAriaExpanded(details[i]);
  i = 0;
  for (i; i < tabpanel.length; i++)
    tabpanel[i].setAttribute('role', 'tabpanel');
  i = 0;
  for (i; i < buttons.length; i++)
    buttons[i].setAttribute('role', 'button');
  addAccessibility(tabs, !0);
  addAccessibility(types, !1);
});